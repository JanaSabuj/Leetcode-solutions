class Solution {
public:
    int lengthOfLastWord(string s) {
        
        stringstream sso;
        sso<<s;
        string x;
        int cnt=0;
        while(sso>>x)
            cnt++;
        
        if(cnt==0)
            return 0;
        else 
            return x.length();
        
        
    }
};