void save_to_disk(struct Graph *g, char *filename){
	int n = 0;
	int l = 0;
	char *name_a, *name_b, line[100];
	FILE * fp;
	strcat(filename, ".gph");
	fp = fopen(filename, "w+");
	while(n < g->num_nodes){
		fprintf(fp, "new %s\n", g->nodes[n].name);
		if(strcmp(g->nodes[n].data, "NULL") != 0){
			fprintf(fp, "wn %s\n%s\n", g->nodes[n].name, g->nodes[n].data);
		}
		n++;
	}
	while(l < g->num_links){
		name_a = get_node_by_id(g->links[l].source, g)->name;
		name_b = get_node_by_id(g->links[l].target, g)->name;
		fprintf(fp, "link %s %s\n", name_a, name_b);
		if(strcmp(g->links[l].data, "NULL") != 0){
			fprintf(fp, "wl %s %s\n%s\n", name_a, name_b, g->links[l].data);
		}
		l++;
	}
	fclose(fp);
}

void read_from_disk(char *filename, struct Graph *g){
	FILE * fp;
	char line[100];
	char name_a[100];
	char name_b[100];
	char type[5];
	strcat(filename, ".gph");
	fp = fopen(filename, "r");
    while (fgets(line, 100, fp) != NULL){
    	if(line[0] == 'w' && line[1] == 'n'){
    		sscanf(line, "%s %s", type, name_a);
    		fgets(line, 100, fp);
    		write_data(line, name_a, g);
    	}
    	else if(line[0] == 'w' && line[1] == 'l'){
    		sscanf(line, "%s %s %s", type, name_a, name_b);
    		fgets(line, 100, fp);
    		write_link_data(line, name_a, name_b, g);
    	} else {
			process_input(line, g);
    	}
    }
    fclose(fp);
}