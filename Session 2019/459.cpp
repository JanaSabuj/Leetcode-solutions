class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.length();
        
        for(int sz = 1; sz <= n/2; sz++){
            // iterate through all possible sizes
            if(n % sz == 0){
                // if a possible substr length
                
                int t = n/sz; // no of substrs
                string tmp;
                
                string part = s.substr(0,sz);
                
                while(t--)// append the part 't' times to get tmp
                    tmp += part;
                
                if (tmp == s)
                    return true;
            }
        }
        
        return false;
        
    }
};