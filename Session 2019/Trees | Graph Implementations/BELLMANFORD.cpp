/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void bellman(const vector<pair<int, pair<int, int>>>& edges, int n, int src) {
	int e = edges.size();// no of edges
	int dist[n];
	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 0; i < n; i++) {
		// relax n-1 times
		for (auto edge : edges) {
			int u = edge.first;
			int v = edge.second.first;
			int wt = edge.second.second;

			if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
				dist[v] = dist[u] + wt;
		}
	}

	// check for neg edge : One extra relaxation
	for (auto edge : edges) {
		int u = edge.first;
		int v = edge.second.first;
		int wt = edge.second.second;

		if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
			dist[v] = dist[u] + wt;
	}

}

int main() {
	freopen("input.txt", "r", stdin);

	int n, e;
	cin >> n >> e;

	vector<pair<int, pair<int, int>>> edges;

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		edges.push_back({u, {v, w}});// edge-list creation
	}

	int src = 0;

	bellman(edges, n, src);// source vertex - src



	return 0;
}


