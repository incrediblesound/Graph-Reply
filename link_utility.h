#ifndef _LINK_UTILITY_H
#define _LINK_UTILITY_H

#include "structures.h"

void write_link_data(char *line, char *name_a, char *name_b, struct Graph *g);
void write_link_data_prompt(char *name_a, char *name_b, struct Graph *g);
void read_link_data(char *name_a, char *name_b, struct Graph *g);
void add_new_link(char *name_a, char *name_b, struct Graph *g);
void get_links(struct Graph *g);
struct Tree *get_outgoing_ids(int source, struct Graph *g);
struct Array *search(int node_id, int target, struct Array *path, struct Graph *g);
void test_for_path(char *name_a, char *name_b, struct Graph *g);

#endif /* _LINK_UTILITY_H */
