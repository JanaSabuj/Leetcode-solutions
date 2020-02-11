/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/
// O(N*2) implementation of Dijkstra's Algorithm
#include <bits/stdc++.h>
using namespace std;

void printAdj(const vector<vector<pair<int, int>>>& adj, int n) {
	for (int i = 0; i < n; i++) {
		for (auto edge : adj[i]) {
			cout << i << " " << edge.first << " " << edge.second << endl;
		}
	}
}

int getMinVertex(int dist[], bool visited[], int n) {
	int mV = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] and (mV == -1 or dist[i] < dist[mV]))
			mV = i;
	}
	return mV;
}

void findPath(int start, int dest, int par[]) {
	std::vector<int> path;
	for (int v = dest; v != -1; v = par[v])
		path.push_back(v);

	reverse(path.begin(), path.end());

	// cout << start <<" "; Not reqd bcoz start can only be the src
	for (auto x : path)
		cout << x << " ";
}

void dijkstra(const vector<vector<pair<int, int>>>& adj, int n, int src) {
	// printAdj(adj, n);
	bool visited[n];
	memset(visited, false, sizeof(visited));

	int dist[n];
	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	int par[n];// parent array
	memset(par, 0, sizeof(par));
	par[src] = -1;// no parent of src

	for (int i = 0; i < n; i++) {
		int u = getMinVertex(dist, visited, n);
		visited[u] = true;

		for (auto edge : adj[u]) {
			int v = edge.first;
			int wt = edge.second;

			if (!visited[v])
				if (dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
					par[v] = u;
				}
		}
	}

	cout << "Distances: " << endl;
	for (int i = 0; i < n; i++) {
		cout << i << " " << dist[i] << endl;// node - dist of the node from the source
	}

	cout << "Path: " << endl;
	int start = src;
	int dest = 3;
	// start -> dest. 
	// Note-> start is ALWAYS the src. All dist w.r.t the src
	findPath(start, dest, par);
}

int main() {
	freopen("input.txt", "r", stdin);

	int n, e;
	cin >> n >> e;

	vector<vector<pair<int, int>>> adj(n);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
	}

	int src = 0;

	dijkstra(adj, n, src);// source vertex - src


	return 0;
}


