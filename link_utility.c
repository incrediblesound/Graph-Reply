#include "link_utility.h"

#include <stdio.h> /* for printf(3) */
#include <stdlib.h> /* for malloc(3), realloc(3), and free(3) */
#include <string.h> /* for strcpy(3), strlen(3), and strcmp(3) */

#include "main_utility.h" /* for get_line() */
#include "node_utility.h" /* for get_id_by_name() and new_or_existing_id() */

void write_link_data(char *line, char *name_a, char *name_b, struct Graph *g){
	int len = strlen(line);
	if(line[len-1] == '\n'){
		line[len-1] = 0;
	}
	int i = 0, src, tgt;
	src = new_or_existing_id(name_a, g);
	tgt = new_or_existing_id(name_b, g);
	while(i < g->num_links){
		if(src == g->links[i].source && tgt == g->links[i].target){
			g->links[i].data = malloc(len+1);
			strcpy(g->links[i].data, line);
			break;
		}
		i++;
	}
}

void write_link_data_prompt(char *name_a, char *name_b, struct Graph *g){
	char *line;
	printf("[(%s->%s).data]> ", name_a, name_b);
	line = get_line();
	write_link_data(line, name_a, name_b, g);
	free(line);
}

void read_link_data(char *name_a, char *name_b, struct Graph *g){
	int i = 0, src, tgt;
	src = new_or_existing_id(name_a, g);
	tgt = new_or_existing_id(name_b, g);
	while(i < g->num_links){
		if(src == g->links[i].source && tgt == g->links[i].target){
			printf("{ \"source\": \"%s\", \"target\": \"%s\", \"data\": \"%s\" }\n", name_a, name_b, g->links[i].data);
			break;
		}
		i++;
	}
}

void add_new_link(char *name_a, char *name_b, struct Graph *g){
	int source = new_or_existing_id(name_a, g);
	int target = new_or_existing_id(name_b, g);
	struct Link new_link;
	new_link.source = source;
	new_link.target = target;
	new_link.data = "NULL";
	g->num_links++;
	g->links[g->num_links-1] = new_link;
}

void get_links(struct Graph *g){
	char *line;
	printf("[link.data]> ");
	line = get_line();
	int len = strlen(line);
	if(line[len-1] == '\n'){
		line[len-1] = 0;
	}
	int first = 0;
	printf("[ ");
	for(int i = 0; i < g->num_links; i++){
		if(!strcmp(line, g->links[i].data)){
			if(first){
				printf(", ");
			} else {
				first = 1;
			}
			printf("[%d, %d]", g->links[i].source, g->links[i].target);
		}
	}
	printf(" ]\n");
	free(line);
}

struct Tree *get_outgoing_ids(int source, struct Graph *g){
	struct Tree *new_tree = (struct Tree *) malloc(sizeof(struct Tree));
	new_tree->root = source;
	struct Array *outgoing = (struct Array *) malloc(sizeof(struct Array));
	outgoing->data = (int *) malloc(sizeof(int));
	outgoing->length = 0;
	new_tree->children = outgoing;
	int i = 0;
	while(i < g->num_links){
		if(g->links[i].source == source){
			outgoing->length++;
			outgoing->data = (int *) realloc(outgoing->data, sizeof(int) * outgoing->length);
			outgoing->data[outgoing->length-1] = g->links[i].target;
		}
		i++;
	}
	return new_tree;
}

struct Array *search(int node_id, int target, struct Array *path, struct Graph *g){
	struct Tree *tree;
	struct Array *newPath = malloc(sizeof(struct Array));
	newPath->length = 0;
	tree = get_outgoing_ids(node_id, g);
	for(int i = 0; i < tree->children->length; i++){
		newPath->length = path->length+1;
		newPath->data = malloc(sizeof(int) * newPath->length);
		for(int l = 0; l < path->length; l++){
			newPath->data[l] = path->data[l];
		}
		newPath->data[newPath->length-1] = tree->children->data[i];
		if(tree->children->data[i] == target){
			return newPath;
		} else {
			newPath = search(tree->children->data[i], target, newPath, g);
		}
	}
	free(tree);
	return newPath;
}

void test_for_path(char *name_a, char *name_b, struct Graph *g){
	int start = get_id_by_name(name_a, g);
	int end   = get_id_by_name(name_b, g);
	struct Array *path = malloc(sizeof(struct Array));
	path->length = 1;
	path->data = malloc(sizeof(int));
	path->data[0] = start;
	struct Array *endPath = search(start, end, path, g);
	if(endPath->length != 0 && endPath->data[endPath->length-1] == end){
		printf("{ \"hasPath\": true, \"path\": [ ");
		for(int i = 0; i < endPath->length; i++){
			if(i > 0){
				printf(", ");
			}
			printf("%d", endPath->data[i]);
		}
		printf(" ] }\n");
	} else {
		printf("{ \"hasPath\": false }\n");
	}
	free(path);
	free(endPath);
}
