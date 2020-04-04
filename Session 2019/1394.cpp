class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(auto x: arr)
            mp[x]++;
        int ans = -1;
        for(auto x: arr)
            if(mp[x] == x)
                ans = max(ans, x);
        
        return ans;                
                
    }
};
