#include <stdio.h>

typedef struct Tnode *btPtr;
typedef struct BT {
	int num;
	btPtr right;
	btPtr left; 
}Tnode;

Tnode* Create();
Tnode* MakeBT(bt1, item, bt2);
Tnode* Lchild(bt);
int Data(bt);
Tnode* Rchild(bt);
void construct_bintree(root);
void BTtoBST(root);
void print_tree(Tnode* root);

int main() {
	Tnode* root;
	root = Create();
	construct_bintree(root);
	print_tree(root);
	BTtoBst(root);
	print_tree(root);
	is_bst(root);
	return 0;
}

Tnode* Create() {
	Tnode *node = malloc(sizeof(Tnode));
	node->left = NULL;
	node->right = NULL;
	return node;
}

Tnode* MakeBT(Tnode *lc, int item, Tnode *rc) {
	Tnode* main = Create();
	main->left = lc;
	main->right = rc;
	main->num = item;
	return main;
}
Tnode* Lchild(Tnode* bt) {
	if (bt->num == NULL) return;
	else return bt->left;
}
int Data(Tnode* bt) {
	if (bt->num == NULL) return;
	else return bt->num;
}
Tnode* Rchild(Tnode* bt) {
	if (bt->num == NULL) return;
	else return bt->right;
}

void construct_bintree(root) {
	Tnode *bt1 = root;
	Tnode *bt2 = Create();
	Tnode *bt3 = Create();
	Tnode *bt4 = Create();
	Tnode *bt5 = Create();
	Tnode *bt6 = Create();
	Tnode *bt7 = Create();
	Tnode *bt8 = Create();
	Tnode *bt9 = Create();
	Tnode *bt10 = Create();

	bt1 = MakeBT(bt2, 30, bt9);
	bt2 = MakeBT(bt3, 70, bt6);
	bt3 = MakeBT(bt4, 50, bt5);
	bt4 = MakeBT(NULL, 20, NULL);
	bt5 = MakeBT(NULL, 40, NULL);
	bt6 = MakeBT(bt7, 90, bt8);
	bt7 = MakeBT(NULL, 10, NULL);
	bt8 = MakeBT(NULL, 80, NULL);
	bt9 = MakeBT(NULL, 95, bt10);
	bt10 = MakeBT(NULL, 60, NULL);
}

void print_tree(Tnode* root) {
	Tnode* node=root;
	Tnode* node2;
	printf("%15d\n",Data(root));
	for (int i = 0; i < 13; i++) {
		printf(" ");
	}
	printf("/  \\\n");
	printf("%12d%4d", Data(root->left), Data(root->right));
	node = root->left;
	node2 = root->right;
	for (int i = 0; i < 10; i++) {
		printf(" ");
	}
	printf("/  \\    \\\n");
	printf("%9d%4d%4d", Data(node->left), Data(node->right),Data(node->right));
}


void BTtoBst(Tnode* root) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {

		}
	}
}



