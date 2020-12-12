class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        
        int cnt = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // cout<<dp[i][j]<<" ";
                if(i == 1)
                    dp[i][j] = mat[i-1][j-1];
                else if(j == 1)
                    dp[i][j] = mat[i-1][j-1];
                else if(mat[i-1][j-1] == 1)
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i - 1][j - 1]}) + 1;
                else
                    dp[i][j] = 0;
                cnt += dp[i][j];
                
            }
            // cout<<endl;
        }
        
        return cnt;
    }
};
