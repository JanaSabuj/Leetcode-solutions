class Solution {
public:
    struct trieNode {
	trieNode* left;
	trieNode* right;
};

void insertx(trieNode* root, int x){
	trieNode* curr = root;

	for(int i = 31; i >= 0; i--){
		int bit = (x>>i)&1;// find ith bit

		if(bit == 0){
			// go to left
			if(!curr->left)
				curr->left = new trieNode();
			curr = curr->left;
		}else if(bit == 1){
			// go to right
			if(!curr->right)
				curr->right = new trieNode();
			curr = curr->right;
		}
	}
}

int queryx(trieNode* root, int x){
	trieNode* curr = root;
	int val = 0;

	for(int i = 31; i >= 0; i--){
		int bit = (x>>i)&1;// find ith bit

		if(bit == 0){
			// go to 1
			if(curr->right){
				val += (1<<i);
				curr = curr->right;
			}
			else
				curr = curr->left;
		}else if(bit == 1){
			// go to 0
			if(curr->left){
				val += (1<<i);
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
	}

	return val;
}


int findMaximumXOR(vector<int>& arr) {
	int n = arr.size();
	trieNode* root = new trieNode();// our trie

	for(int i=0; i<n; i++){
		insertx(root, arr[i]);		
	}

	int ans = 0;

	for(int i=0; i<n; i++){
		ans = max(ans, queryx(root, arr[i]));
	}

	return ans;

}
};
