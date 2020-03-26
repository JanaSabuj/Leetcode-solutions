class Solution {
public:
    int firstUniqChar(string s) {
        map<int,int> mp;
        for(auto c: s)
            mp[c]++;
        
        int n = s.length();
        for(int i = 0; i < n; i++)
            if(mp[s[i]] == 1)
                return i;
        
        return -1;
    }
};