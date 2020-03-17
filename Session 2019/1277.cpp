class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();

		vector<vector<int>> dp(n, vector<int>(m));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 or j == 0)
					dp[i][j] = matrix[i][j];
				else if (matrix[i][j] == 0)
					dp[i][j] = 0;
				else
					dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});

				ans += dp[i][j];
			}
		}

		return ans;
	}
};
