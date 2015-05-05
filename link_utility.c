void write_link_data(char *line, char *name_a, char *name_b, struct Graph *g){
	int len = strlen(line);
	if(line[len-1] == '\n'){
		line[len-1] = 0;
	}
	char *stored = (char *) malloc(sizeof(char) * len);
	strcpy(stored, line);
	int i = 0, src, tgt;
	src = new_or_existing_id(name_a, g);
	tgt = new_or_existing_id(name_b, g);
	while(i < g->num_links){
		if(src == g->links[i].source && tgt == g->links[i].target){
			g->links[i].data = stored;
			break;
		}
		i++;
	}
}

void write_link_data_prompt(char *name_a, char *name_b, struct Graph *g){
	char line[500];
	printf("[(%s->%s).data]> ", name_a, name_b);
	strcpy(line, get_line());
	write_link_data(line, name_a, name_b, g);
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
	struct Link *new_link = (struct Link *) malloc(sizeof(struct Link));
	new_link->source = source;
	new_link->target = target;
	new_link->data = "NULL";
	g->num_links++;
	g->links = (struct Link *) realloc(g->links, sizeof(struct Link) * (g->num_links));
	g->links[g->num_links-1] = *new_link;
}

void get_links(struct Graph *g){
	char line[500];
	printf("[link.data]> ");
	strcpy(line, get_line());
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
}