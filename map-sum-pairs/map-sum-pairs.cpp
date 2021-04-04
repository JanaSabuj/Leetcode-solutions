struct TrieNode{
    int val;
    bool isEnd;
    TrieNode* child[26];
    TrieNode(){
        val = 0;
        isEnd = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string str, int v){
    TrieNode* curr = root;
    for(auto c: str){
        int idx = c - 'a';
        if(curr->child[idx] == NULL)
            curr->child[idx] = new TrieNode();
        curr = curr->child[idx];
    }
    
    curr->isEnd = true;
    curr->val = v;
}

int dfs(TrieNode* curr){
    int sum = 0;
    for(int i = 0; i < 26; i++){
        if(curr->child[i] != NULL)
            sum += dfs(curr->child[i]);
    }
    return sum + curr->val;
}

int query_p(TrieNode* root, string pref){
    TrieNode* curr = root;
    for(auto c: pref){
        int idx = c - 'a';
        if(curr->child[idx] == NULL)
            return 0;
        curr = curr->child[idx];
    }
    
    return dfs(curr);
}

class MapSum {    
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();              
    }
    
    void insert(string key, int val) {
        ::insert(root, key, val);
    }
    
    int sum(string prefix) {
        return query_p(root, prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */