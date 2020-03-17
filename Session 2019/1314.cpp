class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
		int n = mat.size();
		int m = mat[0].size();

		// build sum dp
		vector<vector<int>> sum(n, vector<int>(m));
        sum[0][0] = mat[0][0];
        
		for (int i = 1; i < n; i++)
			sum[i][0] = mat[i][0] + sum[i-1][0];
		for (int j = 1; j < m; j++) {
			sum[0][j] = mat[0][j] + sum[0][j-1];
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		}

		vector<vector<int>> ans(n, vector<int>(m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x1 = max(0, i - k);
				int y1 = max(0, j - k);

				int x2 = min(n - 1, i + k);
				int y2 = min(m - 1, j + k);

				int val = 0;
				if (x1 == 0 and y1 == 0)
					val = sum[x2][y2];
				else if (x1 == 0)
					val = sum[x2][y2] - sum[x2][y1 - 1];
				else if (y1 == 0)
					val = sum[x2][y2] - sum[x1 - 1][y2];
				else
					val = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
				ans[i][j] = val;
			}
		}

		return ans;
	}
};
