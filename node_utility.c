struct Node *get_node_by_id(int id, struct Graph *g){
	struct Node *target;
	for(int i = 0; i < g->num_nodes; i++){
		if(g->nodes[i].id == id){
			target = &g->nodes[i];
		}
	}
	return target;
}

int add_new_node(char *name, struct Graph *g){
	g->num_nodes++;
	int id = g->num_nodes-1;
	g->nodes = (struct Node *) realloc(g->nodes, sizeof(struct Node)*(g->num_nodes));
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	new_node->name = (char *) malloc(sizeof(name));
	strcpy(new_node->name, name);
	new_node->id = id;
	new_node->data = "NULL";
	g->nodes[id] = *new_node;
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

char *return_node_data(char *name, struct Graph *g){
	int i = 0;
	while(strcmp(name, g->nodes[i].name) != 0 && i <= g->num_nodes){
		i++;
	}
	return g->nodes[i].data;
}

void print_outgoing_nodes(char *name, struct Graph *g){
	int id = new_or_existing_id(name, g);
	int first = 0;
	printf("{ ");
	for(int i = 0; i < g->num_links; i++){
		if(g->links[i].source == id){
			if(first){
				printf(", ");
			} else {
				first = 1;
			}
			printf("%s", get_node_by_id(g->links[i].target, g)->name);
		}
	}
	printf(" }\n");
}

void write_data(char *line, char *name, struct Graph *g){
	int len = strlen(line);
	if(line[len-1] == '\n'){
		line[len-1] = 0;
	}
	char *stored = (char *) malloc(sizeof(char) * len);
	strcpy(stored, line);
	int i = 0;
	while(strcmp(name, g->nodes[i].name) != 0 && i <= g->num_nodes){
		i++;
	}
	g->nodes[i].data = stored;
}

void write_data_prompt(char *name, struct Graph *g){
	char line[500];
	printf("[(%s).data]> ", name);
	strcpy(line, get_line());
	write_data(line, name, g);
}

void read_data(char *name, struct Graph *g){
	int i = 0;
	while(strcmp(name, g->nodes[i].name) != 0 && i <= g->num_nodes){
		i++;
	}
	printf("{ \"name\": \"%s\", \"data\": \"%s\" }\n", name, g->nodes[i].data);
}

void get_nodes(struct Graph *g){
	char line[500];
	printf("[node.data]> ");
	strcpy(line, get_line());
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
			printf("{ \"name\": \"%s\" }", g->nodes[i].name);
		}
	}
	printf(" ]\n");
}