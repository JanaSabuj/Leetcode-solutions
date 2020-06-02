class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        map<char, int> mp;
        int n = str.size();
        int i = 0, j = 0;
        
        int ans = 0;
        while(j < n){
            mp[str[j]]++;            
            while(mp[str[j]] > 1){
                mp[str[i]]--;
                i++;
            }                                                
            ans = max(ans, j - i + 1);
            j++;
        }
        
        return ans;
    }
};
