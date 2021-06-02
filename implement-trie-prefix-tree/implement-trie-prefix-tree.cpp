struct TrieNode{
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
            isEnd = false;
        }
    }
};

class Trie {    
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        
        for(auto c: word){
            int x = c - 'a';
            if(curr->child[x] == NULL)
                curr->child[x] = new TrieNode();
            curr = curr->child[x];            
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(auto c: word){
            int x = c - 'a';
            if(curr->child[x] == NULL)
                return false;
            curr = curr->child[x];
        }
        
        return curr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(auto c: prefix){
            int x = c - 'a';
            if(curr->child[x] == NULL)
                return false;
            curr = curr->child[x];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */