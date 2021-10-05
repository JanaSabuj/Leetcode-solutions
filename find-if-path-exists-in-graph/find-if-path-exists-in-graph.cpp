const int N = 2 * 1e5 + 7;

class Solution {
public:
	bool dfs(int x, int end, vector<int> adj[], vector<int>& visited){
		visited[x] = 1;
        cout << x << endl;
		if(x == end)
			return true;
		
		for(auto v: adj[x]){
			if(!visited[v])
				if(dfs(v, end, adj, visited))
					return true;
		}

		return false;
	}

    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {        
        vector<int> adj[n+1];
        vector<int> visited(n+1, 0);
        
        for(auto e: edges){
        	int a = e[0];
        	int b = e[1];
        	adj[a].push_back(b);
        	adj[b].push_back(a);
        }

        return dfs(start, end, adj, visited);
    }
};