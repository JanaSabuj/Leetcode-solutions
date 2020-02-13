class Solution {
public:
    vector<int> countBits(int num) {
        // dp[i] = dp[i - offset] + 1;
        vector<int> dp(num + 1);
        dp[0] = 0;
        int offset = 1;

        for(int i = 1; i <= num; i++){
        	if(offset * 2 == i)
        		offset = i;
        	dp[i] = dp[i - offset] + 1;
        }

        return dp;
    }
};