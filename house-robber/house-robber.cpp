class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] = max amt of money till ith index
        
        
        int n = nums.size();
        if(n == 0)
            return 0;
        
        vector<int> dp(n);
        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            if(i == 1)
                dp[i] = max(nums[i], dp[i-1]);
            else
                dp[i] = max(dp[i-2] + nums[i], dp[i - 1]);
        }
        
        return dp[n-1];
    }
};