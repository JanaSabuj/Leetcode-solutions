class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
         int n = costs.size();
         if(n == 0)
            return 0;
         int k = costs[0].size();
        
            
        int dp[n][k];
        int min_1 = INT_MAX, min_2 = INT_MAX;
        
        for(int i = 0; i < k; i++){
            dp[0][i] = costs[0][i];
            
            if(dp[0][i] <= min_1){
                min_2 = min_1;
                min_1 = dp[0][i];
            }else if(dp[0][i] < min_2){
                min_2 = dp[0][i];
            }
        }
            
        for(int i = 1; i < n; i++){
            int oldmin1 = min_1;
            int oldmin2 = min_2;
            
            min_1 = INT_MAX;
            min_2 = INT_MAX;
            
            for(int j = 0; j < k; j++){
                // dp[i][j] = costs[i][j];
                
                // int val = INT_MAX;
                // for(int kk = 0; kk < k; kk++){
                //     if(kk != j)
                //         val = min(val, dp[i-1][kk]);
                // }
                
                // dp[i][j] += val;
                if(dp[i-1][j] != oldmin1)
                    dp[i][j] = costs[i][j] + oldmin1;
                else
                    dp[i][j] = costs[i][j] + oldmin2;
                
                if(dp[i][j] <= min_1){
                    min_2 = min_1;
                    min_1 = dp[i][j];
                }else if(dp[i][j] < min_2)
                    min_2 = dp[i][j];
            }
        }
        
        int val = INT_MAX;
        for(int i = 0; i < k; i++)
            val = min(val, dp[n-1][i]);
        
        return val;
        
    }
};
// https://www.lintcode.com/problem/paint-house-ii/description
