int tree_contains(int target, struct Tree *tree){
	int contains = 0;
	int i = 0;
	while(i < tree->children->length){
		if(tree->children->data[i] == target){
			contains = 1;
			break;
		}
		i++;
	}
	return contains;
}