/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/
// Bellman Ford 2D DP
#include <bits/stdc++.h>
using namespace std;

void bellman(const vector<pair<int, pair<int, int>>>& edges, int n, int src) {
	// reach from src to a dest using atmost n-1 edges
	vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

	// dp[steps][dest] = min cost incurred to reach dest with atleast `steps` edges

	// src
	for(int i = 0; i < n; i++)
		dp[i][src] = 0;

	for(int i = 1; i < n; i++){
		for(auto edge: edges){
			int u = edge.first;
			int v = edge.second.first;
			int wt = edge.second.second;

			if(dp[i-1][u] != INT_MAX){
				dp[i][v] = min(dp[i][v], dp[i-1][u] + wt); 
			}
		}
	}

	for(int i = 0; i < n; i++){
		cout << i <<" " << dp[n-1][i] << endl;
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


