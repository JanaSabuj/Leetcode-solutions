class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        n = len(A)
        m = len(A[0])

        f = [[None for _ in range(m)] for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if i == 0:
                    f[i][j] = A[i][j]
                else:
                    val = f[i-1][j]
                    for k in [j-1,j,j+1]:
                        if k >= 0 and k < m:
                            val = min(val, f[i-1][k])
                    f[i][j] = val + A[i][j]

        ans = float('inf')
        for j in range(m):
            ans = min(ans, f[n-1][j])
        return ans