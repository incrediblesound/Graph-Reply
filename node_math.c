#include "node_math.h"

#include <stdio.h> /* for printf(3) */
#include <stdlib.h> /* for strtod(3) */

#include "node_utility.h" /* for return_node_data() */

int add_nodes(char *name_a, char *name_b, struct Graph *g){
	double double_val_a, double_val_b;
	int integer_a, integer_b;
	double_val_a = strtod(return_node_data(name_a, g), NULL);
	double_val_b = strtod(return_node_data(name_b, g), NULL);
	double result = double_val_a + double_val_b;
	printf("%f\n", result);
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
	double double_val_a, double_val_b;
	int integer_a, integer_b;
	double_val_a = strtod(return_node_data(name_a, g), NULL);
	double_val_b = strtod(return_node_data(name_b, g), NULL);
	double result = double_val_a - double_val_b;
	printf("%f\n", result);
	return result;
};