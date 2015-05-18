int add_nodes(char *name_a, char *name_b, struct Graph *g){
	long long_val_a, long_val_b;
	int integer_a, integer_b;
	long_val_a = strtol(return_node_data(name_a, g), NULL, 10);
	long_val_b = strtol(return_node_data(name_b, g), NULL, 10);
	int result = long_val_a + long_val_b;
	printf("%d\n", result);
	return result;
};

int divide_nodes(char *name_a, char *name_b, struct Graph *g){
	double double_val_a, double_val_b;
	int integer_a, integer_b;
	double_val_a = strtod(return_node_data(name_a, g), NULL);
	double_val_b = strtod(return_node_data(name_b, g), NULL);
	double result = double_val_a / double_val_b;
	printf("%f\n", result);
	return result;
};

int multiply_nodes(char *name_a, char *name_b, struct Graph *g){
	double double_val_a, double_val_b;
	int integer_a, integer_b;
	double_val_a = strtod(return_node_data(name_a, g), NULL);
	double_val_b = strtod(return_node_data(name_b, g), NULL);
	double result = double_val_a * double_val_b;
	printf("%f\n", result);
	return result;
};

int subtract_nodes(char *name_a, char *name_b, struct Graph *g){
	long long_val_a, long_val_b;
	int integer_a, integer_b;
	long_val_a = strtol(return_node_data(name_a, g), NULL, 10);
	long_val_b = strtol(return_node_data(name_b, g), NULL, 10);
	int result = long_val_a - long_val_b;
	printf("%d\n", result);
	return result;
};