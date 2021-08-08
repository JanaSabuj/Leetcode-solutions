class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        return getWays(n, rollMax);
    }
    
    int getWays(int n, vector<int> maxRolls) {
        // Code here
        // dp[i][j] = no of seq till i throws and ending in j
        const int mod = 1e9 + 7;
        int dp[n + 1][8];

        for (int i = 0; i < 6; i++) {
            dp[1][i] = 1;
        }
        dp[1][6] = 6;

        for (int i = 2; i <= n; i++) {
            int sum = dp[i - 1][6];// prev all sum
            int tot = 0;
            
            for (int j = 0; j < 6; j++) {
                int val = 0;
                int prev_pos_till = i - maxRolls[j] - 1;
                
                if (prev_pos_till < 0)
                    val = val + 0;
                else if (prev_pos_till == 0) {
                    val = val + 1;
                } else {
                    val = val + (dp[prev_pos_till][6] - dp[prev_pos_till][j]) % mod;
                }

                int v = (sum - val) % mod;
                v = (v + mod) % mod;
                dp[i][j] = v;
                tot = (tot + v) % mod;
            }

            dp[i][6] = tot;
        }

        return dp[n][6];
    }
};