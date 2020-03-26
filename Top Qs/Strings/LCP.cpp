class Solution {
public:
    
    string LCP(string a, string b){
        int i = 0, j = 0;
        while(i < (int)a.length() and j < (int)b.length()){
            if(a[i] == b[j]){
                i++;
                j++;
            }else{
                return a.substr(0, i);                
            }
        }
        
        return a.substr(0, i);
         
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
            return "";
        
        string ans = strs[0];
        for(auto str: strs){
            ans = LCP(ans, str);
        }
        return ans;
    }
};