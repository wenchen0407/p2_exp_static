#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h> 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

#define BACKUPS 3
#define BACKLEVELS 7
#define KCONNLEVELS 3
#define CONNECTIVITY 4
#define DATA 9
#define NODES 20


typedef struct probItem{
	map<int, int> nodes_agg; //(node_id, agg_value)
	double prob; 
};

vector<probItem> prob_level1;

std::tr1::unordered_map<string, struct probItem> prob_level2;

std::tr1::unordered_map<string, struct probItem> prob_level3;

int boundary[CONNECTIVITY];

double p_backups[BACKUPS*BACKLEVELS+1];

//std::tr1::unordered_map<string, struct probItem> backup_probs[BACKLEVELS];


double getExp(std::tr1::unordered_map<string, struct probItem>& new_vector, int value){
	double sum = 0.;
	for ( std::tr1::unordered_map<string, probItem>::iterator it = new_vector.begin(); it != new_vector.end(); ++it ){
		map<int, int> mymap = it->second.nodes_agg;
		int sum_value = 0;
		for(int j=0; j<mymap.size(); j++){
			sum_value += mymap.find(j)->second;
		}

		if(sum_value == value){
			sum += it->second.prob;
		}

	}
	return sum;
};



struct probItem* existItem(vector<probItem>& new_vector, struct probItem& item){



	for(int i=0; i<new_vector.size(); i++){
		map<int, int> mymap = new_vector.at(i).nodes_agg;
		int flag = 1;
		//cout << "-------Prob----------" << new_vector.at(i).prob << "mymap size: "<< mymap.size()<<endl;
		for(int j=0; j<mymap.size(); j++){
			//cout << mymap.find(j)->second << ", ";
			//cout << item.nodes_agg.find(j)->second << endl;
			if(mymap.find(j)->second != item.nodes_agg.find(j)->second){
				flag = 0;
			}
		}
		if(flag==1){
			return &(new_vector.at(i));
		}
	}
	return NULL;

};


void getBackupOtherLevelProb(std::tr1::unordered_map<string, struct probItem>& pre_probs, std::tr1::unordered_map<string, struct probItem>& cur_probs, int pre_nodes, int cur_nodes, double p){

	for (std::tr1::unordered_map<string, probItem>::iterator it = pre_probs.begin(); it != pre_probs.end(); ++it){
		vector<probItem> new_vector;
		struct probItem inital_state;
		inital_state.prob = it->second.prob;

		for(int i=0; i<cur_nodes; i++){
			inital_state.nodes_agg.insert(pair<int,int>(i,0));
		}

		new_vector.push_back(inital_state);


		for(int l=0; l<pre_nodes; l++){

			//if(it->second.nodes_agg.find(l)->second != 0 || (it->second.nodes_agg.find(l)->second == 0 && l!=pre_nodes-1)){

				vector<probItem> sub_vector;
				for(int n=0; n<=cur_nodes; n++){

					for(int i=0; i<new_vector.size(); i++){
						struct probItem item = new_vector.at(i);
						// node l in level1 send msg to level2
						if(n==0){

							item.prob = item.prob*pow(1-p,cur_nodes);
							//add(prob_level2, item);
							
						}else{


								item.nodes_agg.find(n-1)->second += it->second.nodes_agg.find(l)->second;
							
							
							//cout << "previous node value: " << prob_level1.probItems_level.at(state_level1).nodes_agg.find(l)->second << endl;
							//cout << "item agg value: " << it->second.nodes_agg.find(n-1)->second << endl;

							item.prob = item.prob*pow(1-p, n-1)*p;

							//add(prob_level2, item);

							
						}
						sub_vector.push_back(item);

					}


				}

				new_vector = sub_vector;

			//}

		}

		/*cout << "------------level---new_vector---size: "<< new_vector.size() << endl;
		double sum = 0.0;
		for(int i=0; i<new_vector.size(); i++){

			//if(prob_level1.probItems_level.at(i).prob > 0.000001){
			sum += new_vector.at(i).prob;
			cout << "prob: " << new_vector.at(i).prob<< endl;
				for(int j=0; j<cur_nodes; j++){
					cout << new_vector.at(i).nodes_agg.find(j)->first << ", "<< new_vector.at(i).nodes_agg.find(j)->second << endl;

				}
			//}
		}
		cout << sum <<endl;*/

		for(int i=0; i<new_vector.size(); i++){
			struct probItem item = new_vector.at(i);
			string str;
			for(int j=0; j<item.nodes_agg.size(); j++){
				stringstream s;
				s << item.nodes_agg.find(j)->second;
				str.append(s.str());
			}
			
			std::tr1::unordered_map<string,probItem>::const_iterator got = cur_probs.find(str);
			if(got == cur_probs.end()){
				cur_probs.insert(pair<string, struct probItem>(str,item));

			}else{
				cur_probs[str].prob += item.prob;
				//got->second.prob += item.prob;
			}
		}

	}

}


void generateBackupProb(double p, int k){

	// calculate no backup situation

	std::tr1::unordered_map<string, struct probItem> nobackup_probs[BACKLEVELS];
	for(int l=0; l<BACKLEVELS; l++){
		if(l==0){

			getBackupOtherLevelProb(prob_level3, nobackup_probs[l], k, 1, p);

		}else{

			getBackupOtherLevelProb(nobackup_probs[l-1], nobackup_probs[l], 1, 1, p);
		}

	}

	for(int d=1; d<=DATA; d++){
		double last_p = getExp(nobackup_probs[BACKLEVELS-1], d);
		p_backups[0] += last_p*d;
		cout << "value: "<< d << " prob: " << last_p << endl;
	}

	for(int b=1; b<=BACKUPS; b++){
		for(int n=0; n<BACKLEVELS; n++){

			//p_backups[(b-1)*BACKLEVELS+n] = 1.0; 
			std::tr1::unordered_map<string, struct probItem> backup_probs[BACKLEVELS];

			for(int l=0; l<BACKLEVELS; l++){
				
				if(l==0){
					getBackupOtherLevelProb(prob_level3, backup_probs[l], k, b+1, p);

				}else if(l<=n){

					getBackupOtherLevelProb(backup_probs[l-1], backup_probs[l], b+1, b+1, p);

				}else if(l == n+1){
					// previous level has b+1 backups. Current level has b backups.
					getBackupOtherLevelProb(backup_probs[l-1], backup_probs[l], b+1, b, p);
					
				}else{
					getBackupOtherLevelProb(backup_probs[l-1], backup_probs[l], b, b, p);

				}

			}

			p_backups[(b-1)*BACKLEVELS+n+1] = getExp(backup_probs[BACKLEVELS-1], 1);

			for(int d=1; d<=DATA; d++){
				double last_p = getExp(backup_probs[BACKLEVELS-1], d);
				p_backups[(b-1)*BACKLEVELS+n+1] += last_p*d;
				cout << "value: "<< d << " prob: " << last_p << endl;
			}

			cout << "The probability of backup "<< (b-1)*BACKLEVELS+n << " is " << p_backups[(b-1)*BACKLEVELS+n]  << endl;
		}
	}	

}


void generateKconnectProb(double p, int k){


	// define level0 inital probItem
	struct probItem inital_state;
	for(int i=0; i<3+k-1; i++){
		inital_state.nodes_agg.insert(pair<int,int>(i,0));

	}
	inital_state.prob = 1.0;


	prob_level1.push_back(inital_state);


	for(int l=0; l<6; l++){
	//for(int l=0; l<1; l++){
		// node l in level0 send msg to level1
		vector<probItem> new_vector;
		for(int n=0; n<=3+k-1; n++){
		//for(int n=0; n<=1; n++){
			for(int i=0; i<prob_level1.size(); i++){
				struct probItem item = prob_level1.at(i);
				if(n==0){
					
					struct probItem* ele = existItem(new_vector, item);
					item.prob = item.prob*pow(1-p,3+k-1);
					new_vector.push_back(item);
					
				}else{

					item.nodes_agg.find(n-1)->second += 1;
					item.prob = item.prob*pow(1-p, n-1)*p;
					new_vector.push_back(item);

					
				}
				
			}

		}


		// sum up probabilities
		vector<probItem> sum_new_vector1;

		for(int i=0; i<new_vector.size(); i++){
			struct probItem item = new_vector.at(i);
			struct probItem* ele = existItem(sum_new_vector1, item);
			if(!ele){
				sum_new_vector1.push_back(item);

			}else{
				ele->prob += item.prob;

			}

		}

		prob_level1= sum_new_vector1;	


	}



	// calculate level2


	for(int state_level1=0; state_level1<prob_level1.size(); state_level1++){

		vector<probItem> new_vector;
		struct probItem inital_state;
		inital_state.prob = prob_level1.at(state_level1).prob;
		for(int i=0; i<k; i++){
			inital_state.nodes_agg.insert(pair<int,int>(i,0));
		}
		new_vector.push_back(inital_state);


		for(int l=0; l<3+k-1; l++){
			
			vector<probItem> sub_vector;
			for(int n=0; n<=k; n++){

				for(int i=0; i<new_vector.size(); i++){
					struct probItem item = new_vector.at(i);
					// node l in level1 send msg to level2
					if(n==0){

						item.prob = item.prob*pow(1-p,k);
						//add(prob_level2, item);
						
					}else{

						if(l<3){
							item.nodes_agg.find(n-1)->second += 1+prob_level1.at(state_level1).nodes_agg.find(l)->second;
						}else{

							item.nodes_agg.find(n-1)->second += prob_level1.at(state_level1).nodes_agg.find(l)->second;
						}
						
						//cout << "previous node value: " << prob_level1.probItems_level.at(state_level1).nodes_agg.find(l)->second << endl;
						//cout << "item agg value: " << prob_level1.at(state_level1).nodes_agg.find(n-1)->second << endl;

						item.prob = item.prob*pow(1-p, n-1)*p;

						//add(prob_level2, item);

						
					}
					sub_vector.push_back(item);

				}


			}

			new_vector = sub_vector;

		}


		for(int i=0; i<new_vector.size(); i++){
			struct probItem item = new_vector.at(i);
			string str;
			//for(int j=0; j<item.nodes_agg.size(); j++){
			for(std::map<int,int>::iterator iter=item.nodes_agg.begin(); iter!=item.nodes_agg.end(); ++iter) {
				stringstream s;
				s << iter->second;
				str.append(s.str());
			}
			
			//cout << "level2 str: " << str << " prob: "<< item.prob <<endl;
			std::tr1::unordered_map<string,probItem>::const_iterator got = prob_level2.find(str);
			if(got == prob_level2.end()){
				prob_level2.insert(pair<string, struct probItem>(str,item));

			}else{
				prob_level2[str].prob += item.prob;
				//got->second.prob += item.prob;
			}
		}

	}



	// calculate level3
	for ( std::tr1::unordered_map<string, probItem>::iterator it = prob_level2.begin(); it != prob_level2.end(); ++it ){
	//for(auto state_level2 = prob_level2.begin(); state_level2!=prob_level2.end(); ++it){
		vector<probItem> new_vector;
		struct probItem inital_state;
		inital_state.prob = it->second.prob;
		for(int i=0; i<k; i++){
			inital_state.nodes_agg.insert(pair<int,int>(i,0));
		}
		new_vector.push_back(inital_state);
		
		for(int l=0; l<k; l++){
			//if(it->second.nodes_agg.find(l)->second != 0 || (it->second.nodes_agg.find(l)->second == 0 && l!=k-1)){
			vector<probItem> sub_vector;

			for(int n=0; n<=k; n++){

				for(int i=0; i<new_vector.size(); i++){
					struct probItem item = new_vector.at(i);

					// node l in level1 send msg to level2
					if(n==0){

						item.prob = item.prob*pow(1-p,k);

						//add(prob_level3, item);
						
					}else{

						item.nodes_agg.find(n-1)->second += it->second.nodes_agg.find(l)->second;
						
						//cout << "previous node value: " << prob_level1.probItems_level.at(state_level1).nodes_agg.find(l)->second << endl;
						//cout << "item agg value: " << item.nodes_agg.find(n-1)->second << endl;

						item.prob = item.prob*pow(1-p, n-1)*p;

						//add(prob_level3, item);
						
					}
					sub_vector.push_back(item);
				}
				
			}

			new_vector = sub_vector;
		//}
		}

		for(int i=0; i<new_vector.size(); i++){
			struct probItem item = new_vector.at(i);
			string str;
			//for(int j=0; j<item.nodes_agg.size(); j++){
			for(std::map<int,int>::iterator iter=item.nodes_agg.begin(); iter!=item.nodes_agg.end(); ++iter) {
				stringstream s;
				s << iter ->second;
				//s << item.nodes_agg.find(j)->second; 
				str.append(s.str());
			}

			//cout << "level3 str: " << str << " prob: "<< item.prob <<endl;
			
			std::tr1::unordered_map<string,probItem>::const_iterator got = prob_level3.find(str);
			if(got == prob_level3.end()){
				//cout << "level3 not found"<< endl;
				prob_level3.insert(pair<string, struct probItem>(str,item));

			}else{

				//cout << "level3 found" << endl;
				prob_level3[str].prob += item.prob;
				//got->second.prob += item.prob;
			}
		}

	}


};

/*void print_all_binary_combination_with_width(int x)
{
	for (int i=0;i<pow(2,x);i++)//loop through permutations
	{
	  for (int j=0;j<x;j++)//loop through binary digits
	  {
	    if(i&int(pow(2,j)))//check digits is 1 or 0
	      cout<<'1';
	    else
	      cout<<'0';
	  }
	  cout<<'\n';
	}
           
};*/

int main(int argc, char *argv[]){

	double link_prob=atof(argv[1]);



	

	for(int k=1; k<=CONNECTIVITY; k++){
		// get probability of kconnect region
		
		prob_level1.clear();
		prob_level2.clear();
		prob_level3.clear();
		
		generateKconnectProb(link_prob, k);

		// get probability of backup region

		for(int back=0; back < BACKUPS*BACKLEVELS+1; back++){
			p_backups[back] = 0.0;
		}

		generateBackupProb(link_prob, k);

		for(int b=0; b<BACKUPS*BACKLEVELS+1; b++){
			cout << "b: "<< b <<" back prob: " << p_backups[b]<< endl;

		}

		
		int nodes = NODES+(k-1)*3;
		string filename = "totalK";
		stringstream s1;
		s1 << k;

		std::ostringstream s2;
		s2 << link_prob;
		filename.append(s1.str());
		filename.append(s2.str());
		ofstream myfile;
		myfile.open (filename.c_str(), ios::trunc);

		double p1=-0.7141;
		double p2=-0.1383;
		double p3=0.3305;

		int flag=0;

		for(int b=0; b<BACKUPS*BACKLEVELS+1; b++){
			//double e = expectations[k-1]*p_backups[b];
			//cout << "back prob: " << p_backups[b]<< endl;
			//cout << "Expectation: " << e << " ";
			double delivery_ratio = p_backups[b]/DATA;
			
			
			cout << "delivery ratio "<< delivery_ratio << endl;

			double delay = ((float)nodes)/((float)100);
			double equation = p1*delay*delay+p2*delay+p3;

			if(1-delivery_ratio <= equation && flag==0){
				boundary[k-1] = nodes;
				flag = 1;
			}

			double delta = equation-(1-delivery_ratio);

			if(delta>0){
				cout << "minimum number of nodes is: " << nodes << endl;
				cout << "delivery ratio is: " << delivery_ratio << endl;
				cout << "network health ratio: " << delta << endl;

				return 0;

			}

			myfile << delivery_ratio;
			myfile << "\t";
			myfile << equation;
			myfile << "\t";
			myfile << delta;
			myfile << "\t";
			myfile << nodes;
			myfile << "\n";
			nodes++;
		}
		myfile.close();

	}

	/*int min_node = 999;
	int min_k=-1;

	for(int i=0; i<CONNECTIVITY; i++){
		cout << "boundary: " << boundary[i]<< endl;
		if(boundary[i]!=0 && boundary[i] <min_node){
			
			min_node = boundary[i];
			min_k=i+1;
		}
	}

	cout << "min_node: " << min_node << endl;
	cout << "min_k: " << min_k << endl;

	// create network initial topology
	string topo_file="topology.txt";
	ofstream topo;
	topo.open (topo_file.c_str(), ios::trunc);
	int remain_node=0;
	int less_level_node = 0;
	int more_level_node = 0;
	int node_counter=0;

	// write the first line
	for(int n=1; n<=min_node; n++){
		topo << n;
		if(n!=min_node){
			topo << " ";
		}
		
	}
	topo << "\n";

	if(min_k == 1){
		topo << "1 2 3 4 5 6\n";
		topo << "7 8 9\n";
		topo << "10\n";
		topo << "11\n";
		node_counter = 11;
		remain_node = min_node - 11;
	}else if (min_k == 2){
		topo << "1 2 3 4 5 6\n";
		topo << "7 8 9 10\n";
		topo << "11 12\n";
		topo << "13 14\n";
		node_counter = 14;
		remain_node = min_node - 14;

	}else if(min_k == 3){
		topo << "1 2 3 4 5 6\n";
		topo << "7 8 9 10 11\n";
		topo << "12 13 14\n";
		topo << "15 16 17\n";
		node_counter = 17;
		remain_node = min_node - 17;


	}else if(min_k == 4){
		topo << "1 2 3 4 5 6\n";
		topo << "7 8 9 10 11 12\n";
		topo << "13 14 15 16\n";
		topo << "17 18 19 20\n";
		node_counter = 20;
		remain_node = min_node - 20;

	}

	less_level_node = (remain_node-1)/BACKLEVELS;
	more_level_node = (remain_node-1)%BACKLEVELS;

	int i, j;

	for(i=1; i<=more_level_node; i++){
		for(j=0; j<less_level_node+1; j++){
			node_counter++;
			topo << node_counter;
			if(j!=less_level_node){
				topo << " ";
			}
			
		}
		topo << "\n";
	}

	for(i=more_level_node+1; i<=BACKLEVELS; i++){
		for(j = 0; j<less_level_node; j++){
			node_counter++;
			topo << node_counter;
			if(j!=less_level_node-1){
				topo << " ";

			}
			
		}
		topo << "\n";
	}

	node_counter++;
	topo << node_counter;
	topo << "\n";
	topo.close();*/
}