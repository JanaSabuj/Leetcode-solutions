class Solution {
public:
	vector<vector<int>> dfs(vector<vector<int>>& adj, int x, int n) {
		// base
		if (x == n - 1) {
			return {{x}};
		}

		// main
		vector<vector<int>> ans;
		for (auto v : adj[x]) {
			// x -> v
			vector<vector<int>> paths = dfs(adj, v, n);
			for (auto subpath : paths) {
				subpath.push_back(x);
				ans.push_back(subpath);
			}
		}

		return ans;
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> paths = dfs(graph, 0, n);
        
        for(auto& path: paths){
            reverse(path.begin(), path.end());
        }
		return paths;
	}
};
