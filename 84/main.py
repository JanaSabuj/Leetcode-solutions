class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
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
