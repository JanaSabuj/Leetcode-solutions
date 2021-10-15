# define RED 0
# define BLUE 1
class Solution {
    int dist[2][105];
public:
    Solution(){
        memset(dist, -1, sizeof(dist));
    }    

    void bfs(int src, vector<pair<int, int>> adj[]) {
        queue<pair<int,int>> q;
        q.push({src, RED});
        q.push({src, BLUE});
        dist[RED][src] = 0;
        dist[BLUE][src] = 0;

        while(!q.empty()){
            auto curr = q.front(); q.pop();
            int v = curr.first;
            int color_prev = curr.second;

            for(auto u: adj[v]){
                if(u.second == !color_prev){                    
                    int to = u.first;
                    int to_color = u.second;
                    if(dist[to_color][to] == -1){
                        dist[to_color][to] = dist[color_prev][v] + 1;
                        q.push({to, to_color});
                    }
                }
            }
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<pair<int, int>> adj[n];   
        for(auto& r: red_edges){
            adj[r[0]].push_back({r[1], RED});
        }

        for(auto& b: blue_edges){
            adj[b[0]].push_back({b[1], BLUE});
        }

        bfs(0, adj);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i){
            cout << dist[RED][i] << " " << dist[BLUE][i] << endl;
            ans[i] = min(dist[RED][i] == -1 ? INT_MAX : dist[RED][i], dist[BLUE][i] == -1 ? INT_MAX : dist[BLUE][i]);
            if(ans[i] == INT_MAX)
                ans[i] = -1;
        }

        return ans;
    }
};