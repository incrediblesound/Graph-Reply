int add_nodes(char *name_a, char *name_b, struct Graph *g){
	long long_val_a, long_val_b;
	int integer_a, integer_b;
	long_val_a = strtol(return_node_data(name_a, g), NULL, 10);
	long_val_b = strtol(return_node_data(name_b, g), NULL, 10);
	integer_a = (int) long_val_a;
	integer_b = (int) long_val_b;
	int result = integer_a + integer_b;
	printf("%s.data + %s.data = %d\n", name_a, name_b, result);
	return result;
};