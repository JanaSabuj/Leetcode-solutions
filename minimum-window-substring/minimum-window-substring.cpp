class Solution {
     unordered_map<char,int> mp;
     unordered_map<char,int> window;
public:                 
     string minWindow(string s, string t) {
         // create base map
        for(auto x: t)
            mp[x]++;
                
        int reqd = mp.size();// no of unique chars                
        int n = s.size();   
         int k = t.size();
         if(n < k)
             return "";
        int formed = 0;
        int l = 0;
         int mx = n + 1;
         int start = -1;
         
        for(int r = 0; r < n; r++){            
            // acquire
            window[s[r]]++;
            if(window[s[r]] == mp[s[r]])
                formed++;
            
            // release
            while(formed == reqd and l <= r){                                                
                if(r - l + 1 <= mx){
                    mx = r - l + 1;
                    start = l;
                }                
                
                window[s[l]]--;
                if(mp.find(s[l]) != mp.end() and window[s[l]] < mp[s[l]])
                    formed--;
                l++;
            }                                  
        }                        
        
         if(start == -1)
             return "";
         
        return s.substr(start, mx);
    }
};
