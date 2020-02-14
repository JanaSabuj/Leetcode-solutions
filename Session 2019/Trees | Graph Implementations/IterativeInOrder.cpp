/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

node* create(int x) {
	node* t = (node*) malloc(sizeof(node));
	t->data = x;
	t->left = NULL;
	t->right = NULL;
}

void iter_inorder(node* root) {
	if (root == NULL)
		return;
	stack<node*> s;

	while (1) {
		if (root != NULL) {
			s.push(root);
			root = root->left;
		} else {
			if (s.empty())
				break;
			root = s.top();
			s.pop();

			cout << root->data << " ";
			root = root->right;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);


	//      1
	//    /   \
	//   2     3
	//  / \   / \
	// 4   5 6   7
	//        \
	//         8

	// create the BT
	node* root = create(1);
	root->left = create(2);
	root->right = create(3);
	root->left->left = create(4);
	root->left->right = create(5);
	root->right->right = create(7);
	root->right->left = create(6);
	root->right->left->right = create(8);

	iter_inorder(root);


	return 0;
}


