class Solution:
    def maximalSquare(self, mat: List[List[str]]) -> int:
        n = len(mat)
        m = len(mat[0])

        mx = 0
        dp = [[0 for _ in range(m)] for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if i == 0 or j == 0:
                    dp[i][j] = 0 if mat[i][j] == "0" else 1
                elif mat[i][j] == "1":
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                else:
                    dp[i][j] = 0

                mx = max(mx, dp[i][j])

        return mx*mx