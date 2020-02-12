/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/
// level order DFS
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

int height(node* root){
	if(root == NULL)
		return 0;
	return max(height(root->left), height(root->right)) + 1;
}

void printLevel(node* root, int level){
	if(root == NULL)
		return;
	if(level == 1)
		cout << root->data <<" ";
	else{
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}

}


void level_dfs(node* root){
	int h = height(root);
	for(int i = 1; i <= h; i++){
		cout << "\nlevel ";
		printLevel(root,i);
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

	// level_dfs
	level_dfs(root);

	return 0;
}


