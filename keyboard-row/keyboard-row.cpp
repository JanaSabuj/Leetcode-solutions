class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        
        unordered_map<char,int> mp;
        for(int i = 0; i < rows.size(); i++){
            for(auto x: rows[i]){
                mp[x] = i + 1;
            }
        }
        
        vector<string> ans;
        for(auto str: words){            
            int row_id = mp[tolower(str[0])];
            
            bool flag = true;
            for(auto x: str){
                if(mp[tolower(x)] != row_id){
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                ans.push_back(str);
        }
        
        return ans;
    }
};