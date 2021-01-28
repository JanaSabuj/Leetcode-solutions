class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = 365
        f = [None] * (n + 1)
        f[0] = 0
        m = len(days)
        last_day = days[m-1]

        s = set()
        for val in days:
        	s.add(val)

        for i in range(1, n + 1):
        	if i not in s:
        		f[i] = f[i - 1]
        		continue

        	f[i] = f[i - 1] + costs[0]
        	if i - 7 >= 0:
        		f[i] = min(f[i], f[i - 7] + costs[1])
        	else:
        		f[i] = min(f[i], costs[1])

        	if i - 30 >= 0:
        		f[i] = min(f[i], f[i - 30] + costs[2])
        	else:
        		f[i] = min(f[i], costs[2])

        	if i == last:
        		break

        return f[last]


