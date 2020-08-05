/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef struct TreeNode node;
class Codec {
    int helper(string& str){
        int pos = str.find(',');
        int val = stoi(str.substr(0, pos));
        str = str.substr(pos + 1);
        
        return val;
    }
    
    node* solve(string& data){
        if(data[0] == '#'){
            if(int(data.size()) > 1)
                data = data.substr(2);
            return NULL;
        }
        
        node* root = new node(helper(data));
        root->left = solve(data);
        root->right = solve(data);
        
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
            
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return solve(data);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
