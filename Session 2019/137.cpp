class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        
        for(auto x:nums)
            mp[x]++;
        
        int val;
        for(auto x:nums)
            if(mp[x] == 1)
            {
                val = x;
                break;
            }
        return val;
    }
};