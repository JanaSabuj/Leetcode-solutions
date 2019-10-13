/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>
using namespace std;

struct nd{
	int data;
	struct nd* left;
	struct nd* right;
};

typedef struct nd node;

node* create(int data){
	node* t = (node*) malloc(sizeof(node));
	t->data = data;
	t->left = NULL;
	t->right = NULL;

	return t;
}

int main() {
	freopen("input.txt", "r", stdin);

	node* root = create(10);
	root->left = create(8);
	root->right = create(2);
	root->left->left = create(3);
	root->left->right = create(5);
	root->right->left = create(2);

	


	return 0;
}


