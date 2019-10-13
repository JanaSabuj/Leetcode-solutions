/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Two trees are identical if they have the same (inorder+preorder) or (inorder+postrorder) traversal

typedef struct TreeNode node;
class Solution {
public:
    
    void inOrder(node* p, vector<int> &v){
        if(p == NULL){
            v.push_back(-1);
            return;}
        
        inOrder(p->left,v);
        v.push_back(p->val);
        inOrder(p->right,v);
    }
    void preOrder(node* p, vector<int> &v){
        if(p == NULL){
            v.push_back(-1);
            return;}
        
        v.push_back(p->val);
        preOrder(p->left,v);
        preOrder(p->right,v);
    }
    
    bool check(vector<int> &v1, vector<int> &v2){
        
         int n=v1.size();
        int m=v2.size();
        
        if(n!=m)
            return false;
        else{
            for(int i=0; i<n; i++){
                if(v1[i]!=v2[i])
                    return false;
            }
            return true;
        }
        
    }
    
    
    bool isSameTree(node* p, node* q) {
        
        vector<int> v1;
        vector<int> v2;
        
        inOrder(p,v1);
        inOrder(q,v2);
        
        bool ans1 = check(v1,v2);
        
        vector<int> a1,a2;
        preOrder(p,a1);
        preOrder(q,a2);
        
        bool ans2 = check(a1,a2);
        
        return ans1 and ans2;
        
       
        
    }
};