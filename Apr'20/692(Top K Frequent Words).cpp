// Map + Heap: O(N log K) time, O(N) space
------------------------------
class Solution {
public:
    class Comp{
        public:
        bool operator()(const pair<string,int>& lhs, const pair<string,int>& rhs){
            // rhs
            // lhs
            
            return (rhs.second < lhs.second or (rhs.second == lhs.second and rhs.first > lhs.first));
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        //1. insert into map
        unordered_map<string,int> mp;
        for(auto& x: words)
            mp[x]++;
        
        //2. insert into heap
        priority_queue<pair<string,int>, vector<pair<string,int>> , Comp> pq;
        
        for(auto pp: mp){            
            pq.push(pp);
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> ans;
        // 2
        // 3
        // 4
        // 2 3 4
        while(!pq.empty()){
            pair<string, int> t = pq.top();
            pq.pop();
            ans.push_back(t.first);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
---------------------------------------------------------------------------
class Solution {
public:
    class TrieNode{
        public:
        TrieNode* child[26];
        string word;
        TrieNode(){
            word = "";
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }                 
    };
    
    void putIn(TrieNode* root, string str){
        TrieNode* curr = root;
        for(auto c: str){
            int x = c - 'a';
            if(curr->child[x] == NULL)
                curr->child[x] = new TrieNode();
            curr = curr->child[x];
        }        
        curr->word = str;// mark as complete  word
    }
    
    void getWords(TrieNode* root, vector<string>& vec, int k){
        if(root == NULL)
            return;
        if(vec.size() == k)
            return;  
        if(root->word != ""){
            vec.push_back(root->word);
        }
      
        for(int i = 0; i < 26; i++){
            if(root->child[i] != NULL)
                getWords(root->child[i], vec, k);
        }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int N = words.size();
        // 1. insert into map
        unordered_map<string,int> mp;
        for(auto x: words)
            mp[x]++;
        
        //2. bucket sort
        // min freq = 1, max freq = N
        TrieNode* count[N + 1];
        for(int i = 0; i <= N; i++)
            count[i] = NULL;
        
        for(auto pp: mp){
            string str = pp.first;
            int x = pp.second;
            
            if(count[x] == NULL)
                count[x] = new TrieNode();            
            putIn(count[x], str);// insert into trie
        }
        
        //3. top k frequent elements        
        vector<string> str;
        for(int i = N; i >= 0; i--){
            if(count[i] == NULL)
                continue;
            getWords(count[i], str, k);
        }
        
        return str;
    }
};
