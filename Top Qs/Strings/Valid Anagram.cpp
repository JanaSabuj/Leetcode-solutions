class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int> mp;
        for(auto c: s)
            mp[c]++;
        for(auto c: t)
            mp[c]--;
        
        for(auto x: mp)
            if(x.second != 0)
                return false;
        return true;
    }
};