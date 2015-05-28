#include <stdio.h> /* for printf(3) */
#include <stdlib.h> /* for free(3) */
#include <string.h> /* for strcmp(3) and strcpy(3) */

#include "input.h" /* for process_input() */
#include "main_utility.h" /* for get_line() */

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
