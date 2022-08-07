class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        //   abcasdfsjfsdllkdf

        //l  ^
        //r  ^

        // substring - think of sliding window
        int n = str.size();
        
        unordered_map<int,int> mp;
        int sz = 0;
        for(int i = 0, j = 0; i <= j and j < n; j++) {
            mp[str[j]]++;
            while(mp[str[j]] > 1) {
                mp[str[i]]--;
                i++;
            }
            sz = max(sz, j - i + 1);
        }
        return sz;
    }
};