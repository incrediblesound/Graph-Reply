#ifndef _NODE_UTILITY_H
#define _NODE_UTILITY_H

#include "structures.h"

struct Node *get_node_by_id(unsigned int id, struct Graph *g);
int add_new_node(char *name, struct Graph *g);
int new_or_existing_id(char *name, struct Graph *g);
int get_id_by_name(char *name, struct Graph *g);
char *return_node_data(char *name, struct Graph *g);
void print_outgoing_nodes(char *name, struct Graph *g);
void print_incoming_nodes(char *name, struct Graph *g);
void write_data(char *line, char *name, struct Graph *g);
void write_data_prompt(char *name, struct Graph *g);
void read_data(char *name, struct Graph *g);
void get_nodes(struct Graph *g);
void run_command(char *name, struct Graph *g);
void print_graph(struct Graph *g);

#endif /* _NODE_UTILITY_H */
