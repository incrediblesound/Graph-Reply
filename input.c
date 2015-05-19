void process_input(char *input, struct Graph *g){
    int i = 0;
    char name_a[50];
    char name_b[50];
    char type[5];
    sscanf(input, "%s %s %s", type, name_a, name_b);
    if(!strcmp(type,"new")){
        add_new_node(name_a, g);
    }
    else if(!strcmp(type,"link")){
        add_new_link(name_a, name_b, g);
    }
    else if(!strcmp(type,"out")){
        print_outgoing_nodes(name_a, g);
    }
    else if(!strcmp(type,"in")){
        print_incoming_nodes(name_a, g);
    }
    else if(!strcmp(type,"wn")){
        write_data_prompt(name_a, g);
    }
    else if(!strcmp(type,"rn")){
        read_data(name_a, g);
    }
    else if(!strcmp(type, "all")){
        print_graph(g);
    }
    else if(!strcmp(type,"wl")){
        write_link_data_prompt(name_a, name_b, g);
    }
    else if(!strcmp(type,"rl")){
        read_link_data(name_a, name_b, g);
    }
    else if(!strcmp(type, "path")){
        // printf("Hey");
        test_for_path(name_a, name_b, g);
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
    else if(!strcmp(type, "div")){
        divide_nodes(name_a, name_b, g);
    }
    else if(!strcmp(type, "sub")){
        subtract_nodes(name_a, name_b, g);
    }
    else if(!strcmp(type, "mult")){
        multiply_nodes(name_a, name_b, g);
    }
    else if(!strcmp(type, "cmd")){
        run_command(name_a, g);
    }
    else if(!strcmp(type, "id")){
        long long_val;
        long_val = strtol(name_a, NULL, 10);
        int id = (int) long_val;
        struct Node *node; 
        node = get_node_by_id(id, g);
        if(!strcmp(node->name, "NULL")){
            printf("{ \"error\": \"No node with id %d\" }\n", id);
            free(node->name);
            free(node);
        } else {
            printf("{ \"id: %d, \"name\": \"%s\", \"data\": \"%s\" }\n", id, node->name, node->data);
        }
    }
}