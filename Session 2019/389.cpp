class Solution {
public:
    char findTheDifference(string s, string t) {
        
        map<int,int> mp;
        for(auto x:s)
            mp[x]++;
        
        map<int,int> np;
        for(auto x:t)
            np[x]++;
        
        char ans;
        for(auto x:np)
            if(np[x.first] > mp[x.first])
            {
                ans = x.first;
                break;
            }
        
        return ans;
    }
};