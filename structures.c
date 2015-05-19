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
	struct Node nodes[10000];
	struct Link links[10000];
	int num_nodes;
	int num_links;
};

struct Array {
	int length;
	int *data;
};

struct Tree {
	int root;
	struct Array *children;
};

struct Forest {
	int levels;
	struct Tree *trees;
};

void process_input(char *, struct Graph *);