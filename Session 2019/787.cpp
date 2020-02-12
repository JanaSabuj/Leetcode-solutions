class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		int dist[n];
		for (int i = 0; i < n; i++)
			dist[i] = INT_MAX;
		dist[src] = 0;

		// atmost K stops
		// atmost K + 1 edges
		for (int i = 1; i <= K + 1 ; i++) {
			for (auto edge : flights) {
				int u = edge[0];
				int v = edge[1];
				int wt = edge[2];

				if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
					dist[v] = dist[u] + wt;
			}
		}

		return (dist[dst] == INT_MAX ? -1 : dist[i]);
	}
};