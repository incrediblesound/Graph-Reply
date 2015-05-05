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
        write_data_prompt(name_a, g);
    }
    else if(!strcmp(type,"rn")){
        read_data(name_a, g);
    }
    else if(!strcmp(type,"wl")){
        write_link_data_prompt(name_a, name_b, g);
    }
    else if(!strcmp(type,"rl")){
        read_link_data(name_a, name_b, g);
    }
    else if(!strcmp(type, "save")){
        save_to_disk(g, name_a);
    }
    else if(!strcmp(type, "load")){
        read_from_disk(name_a, g);
    }
    else if(!strcmp(type, "getl")){
        get_links(g);
        // all links (node pairs) with X data
    }
    else if(!strcmp(type, "getn")){
        get_nodes(g);
        // all nodes with X data
    }
    else if(!strcmp(type, "add")){
        add_nodes(name_a, name_b, g);
    }
    else if(!strcmp(type, "id")){
        long long_val;
        long_val = strtol(name_a, NULL, 10);
        int id = (int) long_val;
        printf("%d\n", id);
        printf("%s\n", get_node_by_id(id, g)->name);
    }
    free(name_a);
    free(name_b);
}