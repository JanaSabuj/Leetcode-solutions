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

void iter_postorder(node* root) {
	if (root == NULL)
		return;

	stack<node*> s1;
	stack<node*> s2;

	s1.push(root);

	while (!s1.empty()) {
		node* t = s1.top();
		s1.pop();
		s2.push(t);

		if (t->left)
			s1.push(t->left);
		if (t->right)
			s1.push(t->right);
	}

	// s2 contains the order
	while(!s2.empty()){
		node* t = s2.top();
		s2.pop();

		cout << t->data <<" ";
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

	iter_postorder(root);


	return 0;
}

