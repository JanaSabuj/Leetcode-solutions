class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        
        for(auto str: strs){
            string can = str;
            sort(can.begin(), can.end());// can
            
            mp[can].push_back(str);
        }
        
        vector<vector<string>> vec;
        for(auto pp: mp){
            vec.push_back(pp.second);
        }
        
        return vec;
        
    }
};
