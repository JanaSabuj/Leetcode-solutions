class Solution {
public:
    int titleToNumber(string s) {
        
        // reverse(s.begin(), s.end());
        
        int ans=0;
        for(int i=0; i<s.length(); i++){
            int val = (s[i] - 65 + 1);
            ans = ans*26 + val;
        }
        
        return ans;
    }
};