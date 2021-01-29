class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		// + + - - + - + -
		int sum = 0;
		for (int x : stones)
			sum += x;
		int m = sum / 2;
		int n = stones.size();

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 and j == 0)
					dp[i][j] = 1;
				else if (i == 0)
					dp[i][j] = 0;
				else if (j == 0)
					dp[i][j] = 1;
				else if (stones[i - 1] <= j)
					dp[i][j] = dp[i - 1][j - stones[i - 1]] || dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		int ans = 0;
		for (int j = m; j >= 0; j--) {
			if (dp[n][j]) {
				ans = j;
				break;
			}
		}

		return sum - 2 * ans;
	}
};