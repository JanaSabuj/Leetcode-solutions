class Solution {
	public int maximalSquare(char[][] mat) {
		int n = mat.length;
		int m = mat[0].length;

		int mx = 0;
		// vector<vector<int>> vec(n, vector<int>(m, 0));
		int[][] dp = new int[n][m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 || j == 0)
					dp[i][j] = (mat[i][j] == '0' ? 0 : 1);
				else if (mat[i][j] == '1')
					dp[i][j] = Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
				else
					dp[i][j] = 0;

				mx = Math.max(mx, dp[i][j]);

			}
		}

		return mx * mx;// return area
	}
}