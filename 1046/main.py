class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        h = [-x for x in stones]
        heapq.heapify(h)

        while len(h) >= 2:
        	a = heapq.heappop(h)
        	b = heapq.heappop(h)

        	heapq.heappush(h, a - b)

        if len(h) == 0:
        	return 0
        else:
        	return -h[0]