class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n = costs.size();
        if(n == 0)
            return 0;
            
        int dp[n][3];
        
        for(int i = 0; i < 3; i++)
            dp[0][i] = costs[0][i];
            
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 3; j++){
                dp[i][j] = costs[i][j];
                
                int val = INT_MAX;
                for(int k = 0; k < 3; k++){
                    if(k != j)
                        val = min(val, dp[i-1][k]);
                }
                
                dp[i][j] += val;
            }
        }
        
        int val = INT_MAX;
        for(int i = 0; i < 3; i++)
            val = min(val, dp[n-1][i]);
        
        return val;
    }
};

// https://www.lintcode.com/problem/paint-house/description
