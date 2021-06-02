class Solution {
    unordered_set<string> dict;
    unordered_map<int,bool> mp;
    int N;
    string str;
public:
    bool solve(int idx){
        // base        
        if(idx == N)
            return true;
        
        if(mp.find(idx) != mp.end())
            return mp[idx];
        
        // main        
        for(int i = 1; i <= N - idx + 1; i++){
            string left = str.substr(idx, i);
            if(dict.find(left) != dict.end() and solve(idx + i))
                return mp[idx] = true;
        }
        
        return mp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x: wordDict){
            dict.insert(x);
        }
        
        N = s.size();
        str = s;
        return solve(0);
    }
};