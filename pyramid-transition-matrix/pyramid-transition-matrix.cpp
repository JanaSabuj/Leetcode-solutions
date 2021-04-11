class Solution {
    unordered_map<string, vector<char>> mp;
public:
    
    bool dfs(string bottom, string tmp){
        // base
        if(bottom.size() == 1)
            return true;
        if(bottom.size() == tmp.size() + 1)
            return dfs(tmp, "");
        
        // main
        for(auto ch: mp[bottom.substr(tmp.size(), 2)]){
            if(dfs(bottom, tmp + ch))
                return true;            
        }
        
        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto str: allowed){
            mp[str.substr(0, 2)].push_back(str[2]);
        }
        
        return dfs(bottom, "");
    }
};