class Solution:
    def numSquares(self, n: int) -> int:
        f = [None] * (n + 1)
        f[0]=0
        f[1]=1
        for i in range(2, n+1):
            f[i] = f[i-1]+1
            for j in range(1, i):
                if j * j <= i:
                    f[i] = min(f[i], f[i - j*j] + 1)
                else:
                    break
        return f[n]