class Solution {
public:

	bool bfsUtil(const vector<vector<int>>& adj, int start, int color[]){

		queue<int> q;
		color[start] = 0;
		q.push(start);

		while(!q.empty()){
			int u = q.front();
			q.pop();

			for(auto x: adj[u]){
				if(color[x] == -1){
					color[x] = !color[u];
					q.push(x);
				}else if(color[x] == color[u]){
					return false;
				}
			}
		}

		return true;
	}

	bool bfs(const vector<vector<int>>& adj, int n){
		int color[n];
		memset(color, -1, sizeof(color));

		for(int i = 0; i < n; i++){
			if(color[i] == -1){
				bool val = bfsUtil(adj, i, color);
				if(!val) return false;
			}
		}

		return true;
	}

    bool isBipartite(vector<vector<int>>& graph) {
    	int n = graph.size();
    	vector<vector<int>> adj(n);
    	for(int i = 0; i < n; i++){
    		// ith- node
    		for(auto x: graph[i])
    			adj[i].push_back(x);
    	}
    	
    	return bfs(adj, n);                        
    }
};
//----------------------------------------------------------------------------
class Solution {
public:

	bool dfsUtil(const vector<vector<int>>& adj, int start, int color[], int c){
		if(color[start] == 0)
			color[start] = c;
		else if(color[start] != c)
			return false;

		int ans = 1;
		for(auto x: adj[start]){
			if(color[x] == 0)
				ans &= dfsUtil(adj, x, color, -c);
			else if(color[x] != -c)
				return false;
			
			if(!ans)
				return false;
		}

		return true;
	}

	bool dfs(const vector<vector<int>>& adj, int n){
		int color[n];
		memset(color, 0, sizeof(color));// unvisited

		for(int i = 0; i < n; i++)
			if(!color[i]){
				int f = dfsUtil(adj, i, color, -1);
				if(!f)
					return false;
			}

		return true;
	}

    bool isBipartite(vector<vector<int>>& graph) {
  		int n = graph.size();
    	vector<vector<int>> adj(n);
    	for(int i = 0; i < n; i++){
    		// ith- node
    		for(auto x: graph[i])
    			adj[i].push_back(x);
    	}

    	return dfs(adj, n);      
    }
};