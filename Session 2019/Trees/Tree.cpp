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

void pre(node* root) {
	if (root == NULL)
		return;

	cout << root->data << endl;
	pre(root->left);
	pre(root->right);
}

void level(node* root) {
	if (root == NULL)
		return;

	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node* curr = q.front();
		q.pop();

		cout << curr->data << " ";

		if (curr->left != NULL)
			q.push(curr->left);

		if (curr->right != NULL)
			q.push(curr->right);
	}
}

void level_line(node* root) {
	if (root == NULL)
		return;

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (1) {
		node* curr = q.front();
		q.pop();

		if (curr != NULL) {
			cout << curr->data << " ";
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		} else {
			cout << endl;
			q.push(NULL);

			if (q.front() == NULL)
				break;// if 2 consecutive NULLs are together, it is the END.
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

	//pre-order traversal DFS
	pre(root);

	//level-order traversal BFS
	cout << "Level Order traversal" << endl;
	level(root);

	//level order line-by-line
	cout << "\nLevel Order traversal line by line " << endl;
	level_line(root);

	return 0;
}


