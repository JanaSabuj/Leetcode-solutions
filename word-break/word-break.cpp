class Solution {
    unordered_set<string> dict;
    unordered_map<string,bool> mp;
public:
    bool solve(string str){
        // base
        int n = str.size();
        if(n == 0)
            return true;
        
        if(mp.find(str) != mp.end())
            return mp[str];
        
        // main        
        for(int i = 1; i <= n; i++){
            string left = str.substr(0, i);
            if(dict.find(left) != dict.end() and solve(str.substr(i)))
                return mp[str] = true;
        }
        
        return mp[str] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x: wordDict){
            dict.insert(x);
        }
        
        return solve(s);
    }
};