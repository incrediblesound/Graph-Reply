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