- DAG ensures no cycle
- since we need all possible paths, no need of visited aray, we can simply backtrack
- by popping back
- K = number of paths = 2^(N-2)
Time comlexity = E + k*V = E + 2^(N-2)*V,
- nc0+nC1+nC2+...+nCn = 2^n
- O(E + k*V)
- k is the max no of times a node can be visited
-max no of paths = max no of times a node can be visited
​
```
So k = no of paths (start + (N-2 optional nodes) + end)
so k = 2^N-2
```
​
- DFS with stack pop, stack populates all paths
​