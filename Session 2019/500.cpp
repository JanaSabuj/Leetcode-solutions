class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        map<char,int> mp;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";
        
        for(auto x:r1){
             mp[x] = 1;
        }
        
        for(auto x:r2){
            mp[x] = 2;
        }
        
        for(auto x:r3)
            mp[x] = 3;
        
        vector<string> req;
        
        for(auto word:words){
            
            set<int> s;
            
            for(auto x:word){
                // cout << mp[x] <<endl;
                s.insert(mp[tolower(x)]);}
            
            
            if(s.size() == 1)
                req.push_back(word);
        }
        
        return req;
            
    }
};