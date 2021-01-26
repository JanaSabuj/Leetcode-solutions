class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();

        vector<vector<int>> f(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0)
                    f[i][j] = A[i][j];
                else {
                    int val = f[i - 1][j];
                    for (int k = j - 1; k <= j + 1; k++)
                        if (k >= 0 and k < m)
                            val = min(val, f[i - 1][k]);

                    f[i][j] = val + A[i][j];
                }
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < m; j++)
            ans = min(ans, f[n - 1][j]);

        return ans;
    }
};