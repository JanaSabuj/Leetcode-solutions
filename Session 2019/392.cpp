class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        int n = t.length();
        int m = s.length();
        
        for(int i=0; i<n; i++){
            if(s[j] == t[i])
                j++;
        }
        
        if(j==m)
            return true;
        else
            return false;
        
    }
};