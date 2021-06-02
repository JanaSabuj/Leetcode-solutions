class Solution {
    unordered_set<string> dict;
    vector<int> mp;
    int N;
    string str;
public:
    bool solve(int idx){
        // base        
        if(idx == N)
            return true;
        
        if(mp[idx] != -1)
            return mp[idx];
        
        // main        
        for(int end = idx; end < N; end++){
            string left = str.substr(idx, end - idx + 1);
            if(dict.find(left) != dict.end() and solve(end + 1))
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
        mp.assign(N + 1, -1);
        return solve(0);
    }
};