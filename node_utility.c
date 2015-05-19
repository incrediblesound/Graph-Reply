struct Node *get_node_by_id(int id, struct Graph *g){
	for(int i = 0; i < g->num_nodes; i++){
		if(g->nodes[i].id == id){
			return &g->nodes[i];
		}
	}
	struct Node *target = malloc(sizeof(struct Node));
	target->name = malloc(5);
	strcpy(target->name, "NULL\0");
	return target;
}

int add_new_node(char *name, struct Graph *g){
	g->num_nodes++;
	int id = g->num_nodes-1;
	struct Node new_node;
	new_node.id = id;
	new_node.data = "NULL";
	g->nodes[id] = new_node;
	g->nodes[id].name = malloc(strlen(name)+1);
	strcpy(g->nodes[id].name, name);
	return id;
}

int new_or_existing_id(char *name, struct Graph *g){
	int id = -1;
	for(int i = 0; i < g->num_nodes; i++){
		if(strcmp(g->nodes[i].name, name) == 0){
			id = g->nodes[i].id;
		}
	}
	if(id == -1){
		id = add_new_node(name, g);
	}
	return id;
}

int get_id_by_name(char *name, struct Graph *g){
	int id = -1;
	for(int i = 0; i < g->num_nodes; i++){
		if(strcmp(g->nodes[i].name, name) == 0){
			id = g->nodes[i].id;
		}
	}
	return id;
}

char *return_node_data(char *name, struct Graph *g){
	int i = 0;
	while(strcmp(name, g->nodes[i].name) != 0 && i <= g->num_nodes){
		i++;
	}
	return g->nodes[i].data;
}

void print_outgoing_nodes(char *name, struct Graph *g){
	int id = get_id_by_name(name, g);
	int first = 0;
	printf("[ ");
	struct Node node[1];
	for(int i = 0; i < g->num_links; i++){
		if(g->links[i].source == id){
			if(first){
				printf(", ");
			} else {
				first = 1;
			}
			node[0] = *get_node_by_id(g->links[i].target, g);
			printf("{ \"id\": %d, \"name\": \"%s\" }", node[0].id, node[0].name);
		}
	}
	printf(" ]\n");
}

void print_incoming_nodes(char *name, struct Graph *g){
	int id = get_id_by_name(name, g);
	int first = 0;
	printf("[ ");
	struct Node node[1];
	for(int i = 0; i < g->num_links; i++){
		if(g->links[i].target == id){
			if(first){
				printf(", ");
			} else {
				first = 1;
			}
			node[0] = *get_node_by_id(g->links[i].source, g);
			printf("{ \"id\": %d, \"name\": \"%s\" }", node[0].id, node[0].name);
		}
	}
	printf(" ]\n");
}

void write_data(char *line, char *name, struct Graph *g){
	int len = strlen(line);
	if(line[len-1] == '\n'){
		line[len-1] = 0;
	}
	int i = 0;
	while(strcmp(name, g->nodes[i].name) != 0 && i <= g->num_nodes){
		i++;
	}
	g->nodes[i].data = malloc(len);
	strcpy(g->nodes[i].data, line);
}

void write_data_prompt(char *name, struct Graph *g){
	char *line;
	printf("[(%s).data]> ", name);
	line = get_line();
	write_data(line, name, g);
	free(line);
}

void read_data(char *name, struct Graph *g){
	if(!g->num_nodes){
		printf("{ error: \"No nodes in graph\" }\n");
		return;
	} else {
		int i = 0;
		while(i < g->num_nodes && strcmp(name, g->nodes[i].name) != 0){
			i++;
		}
		if(i == g->num_nodes){
			printf("{ error: \"No node with name %s\" }\n", name);
		} else {
			printf("{ id: %d, \"name\": \"%s\", \"data\": \"%s\" }\n", g->nodes[i].id, name, g->nodes[i].data);
		}
	}
}

void get_nodes(struct Graph *g){
	char *line;
	printf("[node.data]> ");
	line = get_line();
	int len = strlen(line);
	if(line[len-1] == '\n'){
		line[len-1] = 0;
	}
	int first = 0;
	printf("[ ");
	for(int i = 0; i < g->num_nodes; i++){
		if(!strcmp(line, g->nodes[i].data)){
			if(first){
				printf(", ");
			} else {
				first = 1;
			}
			printf("{ id: %d, \"name\": \"%s\", \"data\": \"%s\" }", g->nodes[i].id, g->nodes[i].name, g->nodes[i].data);
		}
	}
	printf(" ]\n");
	free(line);
}

void run_command(char *name, struct Graph *g){
	if(!g->num_nodes){
		printf("{ error: \"No nodes in graph\" }\n");
		return;
	} else {
		int i = 0;
		while(i < g->num_nodes && strcmp(name, g->nodes[i].name) != 0){
			i++;
		}
		if(i == g->num_nodes){
			printf("{ error: \"No node with name %s\" }\n", name);
		} else {
			process_input(g->nodes[i].data, g);
		}
	}
}

void print_graph(struct Graph *g){
	if(g->num_nodes == 0 && g->num_links == 0){
		printf("{ error: \"No data in graph.\" }\n");
	} else {
		printf("{ ");
		int has_nodes = 0;
		if(g->num_nodes > 0){
			has_nodes = 1;
			printf("\"nodes\": [");
			int i = 0;
			while(i < g->num_nodes){
				if(i > 0 && i <= g->num_nodes-1){
					printf(", ");
				}
				printf("{ \"id\": %d, \"name\": \"%s\", \"data\": \"%s\" }", g->nodes[i].id, g->nodes[i].name, g->nodes[i].data);
				i++;
			}
			printf("]");
		}
		if(g->num_links > 0){
			if(has_nodes){
				printf(", ");
			}
			printf("\"links\": [");
			int l = 0;
			while(l < g->num_nodes){
				if(l > 0 && l <= g->num_nodes-1){
					printf(", ");
				}
				printf("{ \"source\": %d, \"target\": \"%d\", \"data\": \"%s\" }", g->links[l].source, g->links[l].target, g->links[l].data);
				l++;
			}
			printf("] }\n");
		}
	}
}