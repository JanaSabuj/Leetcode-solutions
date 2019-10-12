class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        if(n==0)
            return 0;
        int j;
        for( j=n-1; j>=0;j--){
            if(s[j]!=' ')
                break;
        }
        
        
        int l = 0;
        for(int i=j; i>=0; i--){
            if(s[i] == ' ')
                break;
            l++;
        }
        
        return l;
        
            
        
    }
};