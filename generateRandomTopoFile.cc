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

#define BACKLEVELS 7

int exist_random(vector<int>& random_backups, int random){
	int hasEle=0; 
	for(int j=0; j< random_backups.size(); j++){
		if(random_backups.at(j) == random){
			hasEle = 1;

		}

	}
	return hasEle;

}

int main(int argc, char *argv[]){

	int min_node = atoi(argv[1]);
	int min_k = atoi(argv[2]);
	int linkErrorSeed = atoi(argv[3]);

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
		topo << "7 8 9 10\n";
		topo << "11\n";
		topo << "12\n";
		node_counter = 12;
		remain_node = min_node - 12;
	}else if (min_k == 2){
		topo << "1 2 3 4 5 6\n";
		topo << "7 8 9 10 11\n";
		topo << "12 13\n";
		topo << "14 15\n";
		node_counter = 15;
		remain_node = min_node - 15;

	}else if(min_k == 3){
		topo << "1 2 3 4 5 6\n";
		topo << "7 8 9 10 11 12\n";
		topo << "13 14 15\n";
		topo << "16 17 18\n";
		node_counter = 18;
		remain_node = min_node - 18;


	}else if(min_k == 4){
		topo << "1 2 3 4 5 6\n";
		topo << "7 8 9 10 11 12 13\n";
		topo << "14 15 16 17\n";
		topo << "18 19 20 21\n";
		node_counter = 21;
		remain_node = min_node - 21;
	}

	less_level_node = (remain_node-1)/BACKLEVELS;
	more_level_node = (remain_node-1)%BACKLEVELS;

	vector<int> random_backups;
	srand(linkErrorSeed);
	int k=0;
	while(k<more_level_node){
		int random = 1+(rand()%(int)(BACKLEVELS-1+1));
		if(!exist_random(random_backups, random)){
			random_backups.push_back(random);
			cout << "random: " << random << endl;
			k++;
		}
	}

	int i, j;

	for(i=1; i<=BACKLEVELS; i++){
		if(exist_random(random_backups, i)){
			for(j=0; j<less_level_node+1; j++){
				node_counter++;
				topo << node_counter;
				if(j!=less_level_node){
					topo << " ";
				}
			}
			topo << "\n";
		}else{
			for(j = 0; j<less_level_node; j++){
				node_counter++;
				topo << node_counter;
				if(j!=less_level_node-1){
					topo << " ";
				}
			}
			topo << "\n";
		}

	}

	node_counter++;
	topo << node_counter;
	topo << "\n";
	topo.close();

}