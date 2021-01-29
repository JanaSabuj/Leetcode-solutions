class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        sum = 0
        for x in stones:
            sum += x
        m = sum//2
        n = len(stones)

        dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

        for i in range(0, n + 1):
            for j in range(0, m + 1):                
                if i == 0 and j == 0:
                    dp[i][j] = 1
                elif i == 0:
                    dp[i][j] = 0
                elif j == 0:
                    dp[i][j] = 1
                elif stones[i - 1] <= j:
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - stones[i - 1]]
                else:
                    dp[i][j] = dp[i - 1][j]

        ans = 0
        for j in range(m, -1, -1):
            if dp[n][j] != 0:
                ans = j
                break
                
        return sum - 2 * ans;