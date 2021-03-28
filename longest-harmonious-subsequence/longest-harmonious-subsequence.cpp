class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        
        for(auto x: nums)
            mp[x]++;                
        
        int mx = 0;
        for(auto x: mp){
            int f = x.first;
            
            // both must exist
            if(mp.count(f + 1) > 0)
                mx = max(mx, mp[f] + mp[f + 1]);
        }
        
        return mx;
    }
};
