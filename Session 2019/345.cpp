class Solution {
public:
    
    bool vowel(char c){
        c = tolower(c);
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')
            return true;
        else
            return false;
    }
    
    string reverseVowels(string s) {
        int n = s.length();
        if(n==0 || n==1)
            return s;
        
        int i=0, j=n-1;
        while(i<=j){
            
            char l = s[i];
            if( !vowel(l)){
                i++;
                continue;
            }
            
            char r = s[j];
            if( !vowel(r)){
                j--;
                continue;
            }
                
            
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            
            i++;
            j--;
            
        }
        
        return s;
    }
};