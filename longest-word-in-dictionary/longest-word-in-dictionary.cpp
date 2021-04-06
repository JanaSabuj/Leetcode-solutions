struct TrieNode{
    bool isEnd;
    string word;
    TrieNode* child[26];
};

void insert(TrieNode* root, string str){
    TrieNode* curr = root;
    for(auto c: str){
        int idx = c - 'a';
        if(curr->child[idx] == NULL)
            curr->child[idx] = new TrieNode();
        curr = curr->child[idx];
    }
    
    curr->isEnd = true;
    curr->word = str;
}

void dfs(TrieNode* root, string& res){
    if(root == NULL)
        return;
    
    if(root->isEnd){
        res = root->word.size() > res.size() ? root->word : res;              
    }
    
    for(int i = 0; i < 26; i++){
        if(root->child[i] != NULL and root->child[i]->isEnd)
            dfs(root->child[i], res);
    }
}

class Solution {
    TrieNode* root;
public:
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        for(string w: words){
            insert(root, w);
        }
        
        string res = "";
        dfs(root, res);
        return res;
    }
};