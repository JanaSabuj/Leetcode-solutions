class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        
        int n = prob.size();
        int m = n;
        
        double dp[n+1][m+1];
        
         dp[0][0] = 1.00;
        
        for(int j=1; j <=m; j++)
            dp[0][j] = 0.0;
        
        for(int i=1; i<=n; i++)
            dp[i][0] = dp[i-1][0] * (1.0 - prob[i-1]);
        
       
        
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                dp[i][j] = dp[i-1][j] * (1.0 - prob[i-1]) + dp[i-1][j-1] * prob[i-1];
        
        
//         for(int i=0; i<=n; i++){
//             for(int j=0; j<=m;j++)
//                 cout << dp[i][j] <<" ";
            
//             cout <<endl;
//         }
        
        
        return dp[n][target];
        
        
    }
};