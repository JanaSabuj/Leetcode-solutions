class Solution {
	public int minFallingPathSum(int[][] A) {
		int n = A.length;
		int m = A[0].length;

		// vector<vector<int>> f(n, vector<int>(m, 0));
		int[][] f = new int[n][m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0)
					f[i][j] = A[i][j];
				else {
					int val = f[i - 1][j];
					for (int k = j - 1; k <= j + 1; k++)
						if (k >= 0 && k < m)
							val = Math.min(val, f[i - 1][k]);

					f[i][j] = val + A[i][j];
				}
			}
		}

		int ans = Integer.MAX_VALUE;
		for (int j = 0; j < m; j++)
			ans = Math.min(ans, f[n - 1][j]);

		return ans;
	}
}