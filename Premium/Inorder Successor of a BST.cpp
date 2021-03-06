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
class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
     
     node* minValue(node* root){
        // keep moving as left as possible
         node* curr = root;
         while(curr->left != NULL)
            curr = curr->left;
        return curr;
     }
     
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        if(p == NULL)
            return NULL;
        if(p->right != NULL)
            return minValue(p->right);
            
        node* succ = NULL;
        while(root != NULL){
            if(p->val < root->val){
                succ = root;// possible Successor
                root = root->left;
            }else if(p->val > root->val){
                root = root->right;
            }else
                break;
        }
        
        return succ;
    }
};

// Reverse inorder
----------------------------------------------
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
class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    node* ans = NULL;
    bool flag = false;
    node* req = NULL;
    
    void inorder(node* root, node* p){
        if(root == NULL)
            return;
            
        if(flag)
            return;
            
        cout << "hi" << endl;
        inorder(root->right, p);
        if(root == p){
            req = ans;
            flag = true;
            return;
        }
        ans = root;
        inorder(root->left, p);
    }
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        inorder(root, p);   
        return req;
    }
};
