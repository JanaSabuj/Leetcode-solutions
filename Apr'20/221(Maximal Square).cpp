class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        if(n == 0)
            return 0;
        int m = mat[0].size();
        
        int dp[n][m];
        memset(dp, 0, sizeof(0));
        
        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 or j == 0)
                    dp[i][j] = (mat[i][j] - '0');
                else if(mat[i][j] - '0' == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                
                mx = max(mx, dp[i][j]);                
            }            
        }
        
        return mx * mx;
    }
};
