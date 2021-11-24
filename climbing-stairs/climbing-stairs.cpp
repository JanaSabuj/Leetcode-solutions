class Solution {
    vector<int> dp;
public:
    Solution() {
        dp.assign(46, -1);    
    }
    
    int climbStairs(int n) {
        // base
        if(n < 0)
            return 0;
        if(n == 0)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        // main
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};