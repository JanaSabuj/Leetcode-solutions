class Solution {
    string str;
    int len;    
    vector<string> vec;
public:
    
    void dfs(int idx, string temp){
        
        if(idx == len){
            vec.push_back(temp);
            return;
        }
        
        if(isalpha(str[idx])){
            temp += tolower(str[idx]);
            dfs(idx + 1, temp);
            temp.pop_back();
            
            temp += toupper(str[idx]);
            dfs(idx + 1, temp);
            temp.pop_back();
        }else{
            temp += str[idx];
            dfs(idx + 1, temp);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        str = S;
        len = S.length();        
        vec.clear();
        
        dfs(0, "");
        return vec;
    }
};

USING REFERENCE VARIABLES
------------------------------
    
    class Solution {
    string str;
    int len;    
    vector<string> vec;
public:
    
    void dfs(int idx, string& temp){
        
        if(idx == len){
            vec.push_back(temp);
            return;
        }
        
        if(isalpha(str[idx])){
            temp += tolower(str[idx]);
            dfs(idx + 1, temp);             
            temp.pop_back();
            
            temp += toupper(str[idx]);
            dfs(idx + 1, temp);
            temp.pop_back();
        }else{
            temp += str[idx];
            dfs(idx + 1, temp);  
            temp.pop_back();
        }
        
        return;
    }
    
    vector<string> letterCasePermutation(string S) {
        
        str = S;
        len = S.length();        
        vec.clear();
        
        string ans = "";
        dfs(0, ans);
        return vec;
    }
};
