struct TrieNode{
    TrieNode* child[26];
    bool isEnd;
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
}

bool query(TrieNode* root, string str, int idx, int cnt){
    int n = str.size();
    TrieNode* curr = root;
    
    // base
    if(cnt < 0)
        return false;
    if(idx == n){
        return curr->isEnd and cnt == 0;
    }
    
    // main
    bool found = false;
    for(char ch = 'a'; ch <= 'z'; ch++){
        if(curr->child[ch - 'a'] != NULL){
            if(ch == str[idx])
                found = found | query(curr->child[ch - 'a'], str, idx + 1, cnt);
            else
                found = found | query(curr->child[ch - 'a'], str, idx + 1, cnt - 1);    
        }        
    }
    
    return found;
}

class MagicDictionary {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dict) {
        for(auto str: dict){
            insert(root, str);
        }
    }
    
    bool search(string searchWord) {   
        int cnt = 1;
        return query(root, searchWord, 0, cnt);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */