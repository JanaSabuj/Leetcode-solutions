class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int dp[n][n][2];// max pts Alice will get [i-j] if BOTH play optimally
        // l - 1
        for (int i = 0; i < n; ++i){
            dp[i][i][0] = piles[i];
            dp[i][i][1] = 0;
        }

        for (int i = 0; i < n - 1; ++i){
            dp[i][i+1][0] = max(piles[i], piles[i+1]);
            dp[i][i+1][1] = min(piles[i], piles[i+1]);
        }

        for(int l = 3; l <= n; l++) {
            for(int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;

                dp[i][j][0] = max(piles[i] + dp[i+1][j][1], piles[j] + dp[i][j-1][1]);
                dp[i][j][1] = min(dp[i+1][j][0], dp[i][j-1][0]);
            }
        }

        return dp[0][n-1][0] > dp[0][n-1][1];
    }
};