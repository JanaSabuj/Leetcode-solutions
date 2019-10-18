class Solution {
public:
    int minMoves(vector<int>& nums) {
        int y = *min_element(nums.begin(), nums.end());
        int ans=0;
        for(auto x:nums)
            ans += abs(x - y);
        
        return ans;
    }
};