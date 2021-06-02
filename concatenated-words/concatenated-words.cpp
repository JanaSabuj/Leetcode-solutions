struct TrieNode {
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;            
        }
        isEnd = false;
    }
};

class Trie {
    TrieNode* root;
public:
     
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;

        for (auto c : word) {
            int x = c - 'a';
            if (curr->child[x] == NULL)
                curr->child[x] = new TrieNode();
            curr = curr->child[x];
        }
        curr->isEnd = true;
    }  

    bool concat(string& str, int idx, int cnt) {
       
        if (idx == (int)str.size())
            return cnt >= 2;
        
        TrieNode* curr = root;
        for (int i = idx; i < (int)str.size(); i++) {
         
            int x = str[i] - 'a';
            if (curr->child[x] == NULL)
                return false;
            curr = curr->child[x];
            if (curr->isEnd)
                if (concat(str, i + 1, cnt + 1))
                    return true;
            
            
        }
        
        return false;
    }

};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie tx;
        for (auto x : words) {
            tx.insert(x);
        }

        vector<string> ans;
        for (auto str : words) {
            int n = str.size();
            if (tx.concat(str, 0, 0))
                ans.push_back(str);
        }
        
        return ans;
    }
};