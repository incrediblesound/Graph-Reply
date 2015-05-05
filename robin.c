#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.c"
#include "main_utility.c"
#include "node_utility.c"
#include "link_utility.c"
#include "disk_utility.c"
#include "math.c"
#include "input.c"

int main (){
	char line[100], test[6];
	strcpy(test, "exit\n");
	struct Graph G;
	G.nodes = (struct Node *) malloc(sizeof(struct Node *));
	G.links = (struct Link *) malloc(sizeof(struct Link));
	G.num_nodes = 0; 
	G.num_links = 0;
	while(1) {
		printf("> ");
		strcpy(line, get_line());
		if(strcmp(line, test) == 0) {
			break;
		}
		process_input(line, &G);
	}
};

// n john
// l john mary

