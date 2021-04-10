class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10002;
        vector<int> dp(n, 0);
        
        for(auto x: nums)
            dp[x] += x;
        
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
        }
        
        return dp[n - 1];
    }
};
