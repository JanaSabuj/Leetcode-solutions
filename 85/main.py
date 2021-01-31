def largestHistogramArea(heights: List[int]) -> int:
        s = [] # [(ht, idx)]

        n = len(heights)
        left = [0] * n
        right = [0] * n

        # left NSL
        for i in range(n):
            if len(s) == 0:
                left[i] = -1
            elif heights[i] > s[-1][0]:
                left[i] = s[-1][1]
            else:
                while len(s) != 0 and heights[i] <= s[-1][0]:
                    s.pop()
                if len(s) == 0:
                    left[i] = -1
                else:
                    left[i] = s[-1][1]

            s.append((heights[i], i))

        s = []
        # right NSR
        for i in range(n-1, -1, -1):
            if len(s) == 0:
                right[i] = n
            elif heights[i] > s[-1][0]:
                right[i] = s[-1][1]
            else:
                while len(s) != 0 and heights[i] <= s[-1][0]:
                    s.pop()
                if len(s) == 0:
                    right[i] = n
                else:
                    right[i] = s[-1][1]

            s.append((heights[i], i))   

        mx = 0

        for i in range(n):
            mx = max(mx, heights[i] * (right[i] - left[i] - 1))

        return mx
class Solution:    
    def maximalRectangle(self, mat: List[List[str]]) -> int:
        
        n = len(mat)
        if n == 0:
            return 0
        m = len(mat[0])

        curr = [0] * m
        for j in range(m):
            if mat[0][j] == "0":
                curr[j] = 0
            else:
                curr[j] = 1

        mx = largestHistogramArea(curr)

        for i in range(1, n):
            for j in range(m):
                if mat[i][j] == "0":
                    curr[j] = 0
                else:
                    curr[j] = curr[j] + 1

            mx = max(mx, largestHistogramArea(curr))

        return mx
        