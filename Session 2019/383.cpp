class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mp;
        for(auto x: ransomNote)
            mp[x]++;
        
        map<char,int> np;
        for(auto x:magazine)
            np[x]++;
        
        for(auto x:ransomNote){
            if(mp[x] <= np[x])
                continue;
            else
                return false;
        }
        
        return true;
        
    }
};