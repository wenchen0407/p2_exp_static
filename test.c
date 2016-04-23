#include <stdio.h>
#include <stdlib.h>
#include <string.h>


	int read_rev_file(){
		// read topo_update_log.txt file and generate new network topology by ROOT
		FILE * topo_fp;
	   	char * line = NULL;
	   	size_t len = 0;
	   	ssize_t read;
	   	int i;
	   	char *token;
	   	int line_counter=0;
	   	double curr_network_delay;
	   	int measurements_received;
	   
	   	topo_fp = fopen("/Users/wangwenchen/github/paper2_experiment/received_situation.txt", "r");
	  	if (topo_fp == NULL){
	  		printf("No file???\n");
	       	return 0;
	    }

	   	getline(&line, &len, topo_fp);

	   	token = strtok(line, " ");

	   	curr_network_delay= atof(token);
	   	printf("network delay: %f\n", curr_network_delay);
	   	printf("token:%s", token);
	   	

	   	token = strtok(NULL, " ");

	   	measurements_received = atoi(token);
	   	printf("measuremnt received: %d\n", measurements_received);
	   

	   	


	  	return 1;

	}

	int main(){

		read_rev_file();
		//char *t = "0.03";
		//double test = atof(t);
		//printf("test: %f\n", test);
	}