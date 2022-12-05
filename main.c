#include <stdlib.h>
#include <stdio.h>

struct node {
	struct node* left;
	struct node* right;
	int level;
	int data;
};


struct node* new_node(int data) {
	struct node* node = NULL;
	node = malloc(sizeof(struct node));
	node->left = NULL;
	node->right = NULL;
	node->level = 1;
	node->data = data;
	return node;
}

void insert_node(struct node* root, struct node* node) {
	if (root != NULL && node != NULL) {
		node->level = root->level + 1;
		if (node->data > root->data) {
			if (root->right == NULL)
				root->right = node;
			else
				insert_node(root->right, node);
		} else {
			if (root->left == NULL)
				root->left = node;
			else
				insert_node(root->left, node);
		}
	}
}

int search(struct node* tree, int data) {
	int l = 0;
	if (tree == NULL)
		return 0;
	if (tree->data == data)
		return tree->level;
	l = search(tree->left, data);
	if (l > 0)
		return l;
	l = search(tree->right, data);
	if (l > 0)
		return l;
	return 0;
}

int main() {
	int n = 0, level = 0;
	struct node* tree = new_node(6);
	insert_node(tree, new_node(5));
	insert_node(tree, new_node(11));
	insert_node(tree, new_node(4));
	insert_node(tree, new_node(3));
	insert_node(tree, new_node(8));
	insert_node(tree, new_node(12));
	insert_node(tree, new_node(9));
	insert_node(tree, new_node(21));
	
	printf("Introduzca el numero a buscar:\n");
	scanf("%d", &n);
	level = search(tree, n);
	if (level > 0)
		printf("El numero %d esta en %d er/to nivel: \n",n, level);
	else 
		printf("Numero %d no encontrado\n",n);

	return 0;
}
