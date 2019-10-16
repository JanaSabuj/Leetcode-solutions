class Solution {
public:
    int longestPalindrome(string s) {
        
        int n= s.length();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        map<char,int> mp;
        for(auto x:s)
            mp[x]++;
        
        int len=0;
        bool odd = false;
        for(auto x:mp){
            if(x.second%2 == 0)
                len += x.second;
            else{
                odd = true;
                len +=(x.second - 1);
            }
                
        }
        
        if(odd)
             return len + 1;
        else
            return len;
        
    }
};