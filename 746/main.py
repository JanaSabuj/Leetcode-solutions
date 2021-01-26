class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        f = [None] * (n + 1)
        
        f[0] = 0
        f[1] = 0
        
        for i in range(2, n + 1):
            f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2])
        return f[n]
        
        
        