#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.c"
#include "tree_utility.c"
#include "main_utility.c"
#include "node_utility.c"
#include "link_utility.c"
#include "disk_utility.c"
#include "math.c"
#include "input.c"

int main (){
	char *line, test[6];
	strcpy(test, "exit\n");
	struct Graph G;
	G.num_nodes = 0; 
	G.num_links = 0;
	while(1) {
		printf("> ");
		line = get_line();
		if(strcmp(line, test) == 0) {
			free(line);
			break;
		}
		process_input(line, &G);
		free(line);
	}
	int i = 0;
	while(i < G.num_nodes){
		free(G.nodes[i].name);
		i++;
	}
};
