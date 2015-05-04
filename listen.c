#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
	char *name;
	char *data;
	unsigned int id;
};

struct Link {
	int source;
	int target;
	char *data;
};

struct Graph {
	struct Node *nodes;
	struct Link *links;
	int num_nodes;
	int num_links;
};

char *get_line() {
    char * line = malloc(100), * linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        if(c == EOF)
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }
    *line = '\0';
    return linep;
};

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
	new_node->name = name;
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

void write_link_data(char *name_a, char *name_b, struct Graph *g){
	char line[500];
	printf("[(%s->%s).data]:>", name_a, name_b);
	strcpy(line, get_line());
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

void read_link_data(char *name_a, char *name_b, struct Graph *g){
	int i = 0, src, tgt;
	src = new_or_existing_id(name_a, g);
	tgt = new_or_existing_id(name_b, g);
	while(i < g->num_links){
		if(src == g->links[i].source && tgt == g->links[i].target){
			printf("[(%s->%s).data]:=\"%s\"\n", name_a, name_b, g->links[i].data);
			break;
		}
		i++;
	}
}

void write_data(char *name, struct Graph *g){
	char line[500];
	printf("[(%s).data]:>", name);
	strcpy(line, get_line());
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

void read_data(char *name, struct Graph *g){
	int i = 0;
	while(strcmp(name, g->nodes[i].name) != 0 && i <= g->num_nodes){
		i++;
	}
	printf("[(%s).data]:=\"%s\"\n", name, g->nodes[i].data);
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

void save_to_disk(struct Graph *g){
	int n = 0;
	int l = 0;
	char filename[20], ext[10], name[30], line[100];
	FILE * fp;
	printf("[file name]:>");
	strcpy(filename, get_line());
	strcat(filename, ".txt");
	fp = fopen(filename, "w+");
		// fprintf(fp, "%s\n", line);
	while(n < g->num_nodes){
		fprintf(fp, "node %s\n", g->nodes[n].name);
		if(strcmp(g->nodes[n].data, "NULL") != 0){
			fprintf(fp, "node_data %s %s\n", g->nodes[n].name, g->nodes[n].data);
		}
		n++;
	}
	printf("%s\n", "HEy");
	while(l < g->num_links){
		fprintf(fp, "link %d %d\n", g->links[l].source, g->links[l].target);
		if(strcmp(g->links[l].data, "NULL") != 0){
			fprintf(fp, "link_data %d %d %s\n", g->links[l].source, g->links[l].target, g->links[l].data);
		}
		l++;
	}
	fclose(fp);
}

void process_input(char *input, struct Graph *g){
	int i = 0;
	char *name_a = (char *) malloc(sizeof(char)*100);
	char *name_b = (char *) malloc(sizeof(char)*100);
	char type[5];
	sscanf(input, "%s %s %s", type, name_a, name_b);
	if(!strcmp(type,"node")){
		add_new_node(name_a, g);
	}
	else if(!strcmp(type,"link")){
		add_new_link(name_a, name_b, g);
	}
	else if(!strcmp(type,"out")){
		print_outgoing_nodes(name_a, g);
	}
	else if(!strcmp(type,"wn")){
		write_data(name_a, g);
	}
	else if(!strcmp(type,"rn")){
		read_data(name_a, g);
	}
	else if(!strcmp(type,"wl")){
		write_link_data(name_a, name_b, g);
	}
	else if(!strcmp(type,"rl")){
		read_link_data(name_a, name_b, g);
	}
	else if(!strcmp(type, "save")){
		save_to_disk(g);
	}
}

int main (){
	char line[100], test[6];
	strcpy(test, "exit\n");
	struct Graph G;
	G.nodes = (struct Node *) malloc(sizeof(struct Node *));
	G.links = (struct Link *) malloc(sizeof(struct Link));
	G.num_nodes = 0; 
	G.num_links = 0;
	while(1) {
		strcpy(line, get_line());
		if(strcmp(line, test) == 0) {
			break;
		}
		process_input(line, &G);
	}
	int i = 0;
	while(i < G.num_nodes){
		printf("%d\n", i);
		printf("%s\n", G.nodes[i].name);
		i++;
	}
};

// n john
// l john mary

