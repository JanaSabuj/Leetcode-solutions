// https://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters/description
class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
     bool valid(unordered_map<char,int>& mp, int k){
         return mp.size() <= k;
     }
    int lengthOfLongestSubstringKDistinct(string &str, int k) {
        // write your code here
        int l = 0, r = 0;
         
        unordered_map<char,int> mp;
        int len = INT_MIN;
        int n = str.length();
        if(n == 0)
            return 0;
            
        while(r < n){
            mp[str[r]]++;
            
            while(!valid(mp, k)){
                // s.erase(str[l]);
                if(mp[str[l]] == 1)
                    mp.erase(str[l]);
                else
                    mp[str[l]]--;
                    
                l++;
            }
            
            // cout << r - l + 1 << endl;
            len = max(len, r - l + 1);
            r++;
        }
        
        return len;
        
    }
};
