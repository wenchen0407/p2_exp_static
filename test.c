#include <stdio.h>
#include <stdlib.h>
//#include <tgmath.h> 
//#include <iostream>
//#include <fstream>
#include <string.h>
//#include <sstream>
//#include <map>
//#include <vector>
//#include <tr1/unordered_map>

#define BACKLEVELS 7

void generateUpTopoFile(int min_node, int min_k){

	FILE* fp_new_topo;
	int remain_node=0;
	int less_level_node = 0;
	int more_level_node = 0;
	int node_counter=0;
	int n;
	int i, j;
	int node_counter_start=22;
	//cout << "min_node: " << min_node << endl;
	//cout << "min_k: " << min_k << endl;

	printf("min_node: %d\n", min_node);
	printf("min_k: %d\n", min_k);

	// create network initial topology
	fp_new_topo = fopen("/Users/wangwenchen/github/paper2_experiment/topology.txt", "w");

	

	// write the first line
	for(n=1; n<=min_node; n++){
		fprintf(fp_new_topo, "%d", n);
		//topo << n;
		if(n!=min_node){

			fprintf(fp_new_topo, " ");
		}
		
	}

	fprintf(fp_new_topo, "\n");

	if(min_k == 1){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10\n";
		//topo << "14\n";
		//topo << "18\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10\n");
		fprintf(fp_new_topo, "14\n");
		fprintf(fp_new_topo, "18\n");

		node_counter = 12;
		remain_node = min_node - 12;
	}else if (min_k == 2){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10 11\n";
		//topo << "14 15\n";
		//topo << "18 19\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10 11\n");
		fprintf(fp_new_topo, "14 15\n");
		fprintf(fp_new_topo, "18 19\n");

		node_counter = 15;
		remain_node = min_node - 15;

	}else if(min_k == 3){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10 11 12\n";
		//topo << "14 15 16\n";
		//topo << "18 19 20\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10 11 12\n");
		fprintf(fp_new_topo, "14 15 16\n");
		fprintf(fp_new_topo, "18 19 20\n");

		node_counter = 18;
		remain_node = min_node - 18;


	}else if(min_k == 4){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10 11 12 13\n";
		//topo << "14 15 16 17\n";
		//topo << "18 19 20 21\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10 11 12 13\n");
		fprintf(fp_new_topo, "14 15 16 17\n");
		fprintf(fp_new_topo, "18 19 20 21\n");

		node_counter = 21;
		remain_node = min_node - 21;
	}

	less_level_node = (remain_node-1)/BACKLEVELS;
	more_level_node = (remain_node-1)%BACKLEVELS;


	node_counter=0;
	for(i=1; i<=more_level_node; i++){
		for(j=0; j<less_level_node+1; j++){
			//topo << node_counter+node_counter_start;
			fprintf(fp_new_topo, "%d", node_counter+node_counter_start);

			if(j!=less_level_node){
				//topo << " ";
				fprintf(fp_new_topo, " ");
			}
			node_counter++;
			
		}
		//topo << "\n";
		fprintf(fp_new_topo, "\n");
		node_counter_start += 4;
		node_counter=0;

	}

	for(i=more_level_node+1; i<=BACKLEVELS; i++){
		for(j = 0; j<less_level_node; j++){
			//topo << node_counter+node_counter_start;
			fprintf(fp_new_topo, "%d", node_counter+node_counter_start);
			if(j!=less_level_node-1){
				//topo << " ";
				fprintf(fp_new_topo, " ");
			}
			node_counter++;
		}
		//topo << "\n";
		fprintf(fp_new_topo, "\n");
		node_counter_start += 4;
		node_counter=0;
	}

	//topo << "50";
	//topo << "\n";
	//topo.close();
	fprintf(fp_new_topo, "50");
	fclose(fp_new_topo);

}

void generateDownTopoFile(int min_node, int min_k){

	FILE* fp_new_topo;
	int remain_node=0;
	int less_level_node = 0;
	int more_level_node = 0;
	int node_counter=0;
	int n;
	int i, j;
	int node_counter_start=22;

	//cout << "min_node: " << min_node << endl;
	//cout << "min_k: " << min_k << endl;

	printf("min_node: %d\n", min_node);
	printf("min_k: %d\n", min_k);

	// create network initial topology
	fp_new_topo = fopen("/Users/wangwenchen/github/paper2_experiment/topology.txt", "w");

	

	// write the first line
	for(n=1; n<=min_node; n++){
		fprintf(fp_new_topo, "%d", n);
		//topo << n;
		if(n!=min_node){

			fprintf(fp_new_topo, " ");
		}
		
	}

	fprintf(fp_new_topo, "\n");

	if(min_k == 1){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10\n";
		//topo << "14\n";
		//topo << "18\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10\n");
		fprintf(fp_new_topo, "14\n");
		fprintf(fp_new_topo, "18\n");

		node_counter = 12;
		remain_node = min_node - 12;
	}else if (min_k == 2){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10 11\n";
		//topo << "14 15\n";
		//topo << "18 19\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10 11\n");
		fprintf(fp_new_topo, "14 15\n");
		fprintf(fp_new_topo, "18 19\n");

		node_counter = 15;
		remain_node = min_node - 15;

	}else if(min_k == 3){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10 11 12\n";
		//topo << "14 15 16\n";
		//topo << "18 19 20\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10 11 12\n");
		fprintf(fp_new_topo, "14 15 16\n");
		fprintf(fp_new_topo, "18 19 20\n");

		node_counter = 18;
		remain_node = min_node - 18;


	}else if(min_k == 4){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10 11 12 13\n";
		//topo << "14 15 16 17\n";
		//topo << "18 19 20 21\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10 11 12 13\n");
		fprintf(fp_new_topo, "14 15 16 17\n");
		fprintf(fp_new_topo, "18 19 20 21\n");

		node_counter = 21;
		remain_node = min_node - 21;
	}

	less_level_node = (remain_node-1)/BACKLEVELS;
	more_level_node = (remain_node-1)%BACKLEVELS;

	node_counter=0;
	for(i=1; i<=BACKLEVELS-more_level_node; i++){
		for(j=0; j<less_level_node; j++){
			//topo << node_counter+node_counter_start;
			fprintf(fp_new_topo, "%d", node_counter+node_counter_start);

			if(j!=less_level_node-1){
				//topo << " ";
				fprintf(fp_new_topo, " ");
			}
			node_counter++;
			
		}
		//topo << "\n";
		fprintf(fp_new_topo, "\n");
		node_counter_start += 4;
		node_counter=0;

	}

	for(i=BACKLEVELS-more_level_node+1; i<=BACKLEVELS; i++){
		for(j = 0; j<less_level_node+1; j++){
			//topo << node_counter+node_counter_start;
			fprintf(fp_new_topo, "%d", node_counter+node_counter_start);
			if(j!=less_level_node){
				//topo << " ";
				fprintf(fp_new_topo, " ");
			}
			node_counter++;
		}
		//topo << "\n";
		fprintf(fp_new_topo, "\n");
		node_counter_start += 4;
		node_counter=0;
	}

	//topo << "50";
	//topo << "\n";
	//topo.close();
	fprintf(fp_new_topo, "50");
	fclose(fp_new_topo);

}

void generateRandomTopoFile(int min_node, int min_k, int linkErrorSeed){

	FILE* fp_new_topo;
	int remain_node=0;
	int less_level_node = 0;
	int more_level_node = 0;
	int node_counter=0;
	int n;
	int i, j;
	int node_counter_start=22;
	int random_backups[BACKLEVELS] = {0, 0, 0, 0, 0, 0, 0};
	int k=0;

	//cout << "min_node: " << min_node << endl;
	//cout << "min_k: " << min_k << endl;

	printf("min_node: %d\n", min_node);
	printf("min_k: %d\n", min_k);

	// create network initial topology
	fp_new_topo = fopen("/Users/wangwenchen/github/paper2_experiment/topology.txt", "w");

	

	// write the first line
	for(n=1; n<=min_node; n++){
		fprintf(fp_new_topo, "%d", n);
		//topo << n;
		if(n!=min_node){

			fprintf(fp_new_topo, " ");
		}
		
	}

	fprintf(fp_new_topo, "\n");

	if(min_k == 1){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10\n";
		//topo << "14\n";
		//topo << "18\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10\n");
		fprintf(fp_new_topo, "14\n");
		fprintf(fp_new_topo, "18\n");

		node_counter = 12;
		remain_node = min_node - 12;
	}else if (min_k == 2){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10 11\n";
		//topo << "14 15\n";
		//topo << "18 19\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10 11\n");
		fprintf(fp_new_topo, "14 15\n");
		fprintf(fp_new_topo, "18 19\n");

		node_counter = 15;
		remain_node = min_node - 15;

	}else if(min_k == 3){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10 11 12\n";
		//topo << "14 15 16\n";
		//topo << "18 19 20\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10 11 12\n");
		fprintf(fp_new_topo, "14 15 16\n");
		fprintf(fp_new_topo, "18 19 20\n");

		node_counter = 18;
		remain_node = min_node - 18;


	}else if(min_k == 4){
		//topo << "1 2 3 4 5 6\n";
		//topo << "7 8 9 10 11 12 13\n";
		//topo << "14 15 16 17\n";
		//topo << "18 19 20 21\n";

		fprintf(fp_new_topo, "1 2 3 4 5 6\n");
		fprintf(fp_new_topo, "7 8 9 10 11 12 13\n");
		fprintf(fp_new_topo, "14 15 16 17\n");
		fprintf(fp_new_topo, "18 19 20 21\n");

		node_counter = 21;
		remain_node = min_node - 21;
	}

	less_level_node = (remain_node-1)/BACKLEVELS;
	more_level_node = (remain_node-1)%BACKLEVELS;


	srand(linkErrorSeed);
	
	while(k<more_level_node){
		int random = 1+(rand()%(int)(BACKLEVELS-1+1));
		if(!exist_random(random_backups, random)){
			random_backups[k] = random;
			//cout << "random: " << random << endl;
			printf("random_backups: %d\n", random_backups[k]);
			k++;
		}
	}


	node_counter=0;


	for(i=1; i<=BACKLEVELS; i++){
		if(exist_random(random_backups, i)){
			for(j=0; j<less_level_node+1; j++){
				
				fprintf(fp_new_topo, "%d", node_counter+node_counter_start);
				if(j!=less_level_node){
					fprintf(fp_new_topo, " ");
				}
				node_counter++;
			}
			fprintf(fp_new_topo, "\n");
			node_counter_start += 4;
			node_counter=0;
		}else{
			for(j = 0; j<less_level_node; j++){
				
				fprintf(fp_new_topo, "%d", node_counter+node_counter_start);
				if(j!=less_level_node-1){
					fprintf(fp_new_topo, " ");
				}
				node_counter++;
			}
			fprintf(fp_new_topo, "\n");
			node_counter_start += 4;
			node_counter=0;
		}

	}

	fprintf(fp_new_topo, "50");
	fclose(fp_new_topo);

}

int exist_random(int *random_backups, int random){
	int hasEle = 0;
	int j=0;
	for(j=0; j<BACKLEVELS; j++){
		if(random_backups[j] == random){
			hasEle = 1;
		}
	}
	return hasEle;
}



int main(int argc, char *argv[]){
	generateDownTopoFile(atoi(argv[1]), atoi(argv[2]));

	return 0;
}