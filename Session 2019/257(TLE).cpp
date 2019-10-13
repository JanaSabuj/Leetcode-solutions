/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;

struct nd {
	int data;
	struct nd* left;
	struct nd* right;
};

typedef struct nd node;

node* create(int data) {
	node* t = (node*) malloc(sizeof(node));
	t->data = data;
	t->left = NULL;
	t->right = NULL;

	return t;
}

void printPathPre(node* root, vector<int> &vec, int len) {

	if (root == NULL)
		return;

	vec[len] = root->data;
	// vec.push_back(root->data);
	len++;

	// if leaf
	if (root->left == NULL and root->right == NULL) {
		for (int i = 0; i < len; i++)
			cout << vec[i] << " ";
		cout << endl;
	}

	printPathPre(root->left, vec, len);
	printPathPre(root->right, vec, len);


}

void printPath(node* root) {
	std::vector<int> vec(100000);
	int len = 0;

	printPathPre(root, vec, len);

}

int main() {
	freopen("input.txt", "r", stdin);

	node* root = create(10);
	root->left = create(8);
	root->right = create(2);
	root->left->left = create(3);
	root->left->right = create(5);
	root->right->left = create(2);

	printPath(root);


	return 0;
}


