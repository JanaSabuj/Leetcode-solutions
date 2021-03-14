class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto str: strs){
             
            string t = str;
            sort(t.begin(), t.end());            
            mp[t].push_back(str);
        }
        
        vector<vector<string>> vec;
        for(auto pp: mp){
            vec.push_back(pp.second);
        }
        
        return vec;        
    }
};