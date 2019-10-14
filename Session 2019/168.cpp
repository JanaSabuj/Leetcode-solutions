class Solution {
public:
    string convertToTitle(int n) {
        
        string ans="";
        
        while(n-->0){
            int val = n%26 ;
            char c = val + 65;
            ans = ans + c;
            
            n/=26;
        }
        
        // cout << ans;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};