class Solution {
public:
    #define inf 1000000007
    int dieSimulator(int n, vector<int>& rollMax) {
        // int dp[rolls][no][cnt]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(6, vector<int>(16, 0)));
        
        // dp[r = 1][n][c]
        for(int j = 0; j < 6; j++){
            dp[0][j][1] = 1;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 6; j++){
                
                // case 1 : dp[r][n][1]
                for(int k = 0; k < 6; k++){
                    if(k == j) continue;
                    for(int m = 1; m <= rollMax[k]; m++){
                        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][m]) % inf;
                    }
                }
                
                // case 2: dp[r][n][>=2]
                for(int m = 2; m <= rollMax[j]; m++){
                    dp[i][j][m] = dp[i - 1][j][m - 1];
                }
            }
        }
        
        int cnt = 0;
        for(int j = 0; j < 6; j++){
            for(int k = 1; k <= rollMax[j]; k++){
                cnt =  (cnt + dp[n - 1][j][k]) % inf;
            }
        }
        
        return cnt;
     }
};
// general house paint, no consecutive houses same color
// dp[h][c] = sum(dp[h - 1][cc]) cc != c