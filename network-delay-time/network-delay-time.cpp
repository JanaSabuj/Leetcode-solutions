class Solution {
    vector<vector<pair<int,int>>> adj;
    vector<int> dist;
    const int inf = 1e9;
public:
    
    void dijkstra(int src){
        set<pair<int,int>> q;
        q.insert({0, src});
        dist[src] = 0;
        
        while(!q.empty()){
            int v = q.begin()->second;
            q.erase(q.begin());
            
            for(auto edge: adj[v]){
                int to = edge.first;
                int len = edge.second;
                
                if(dist[v] + len < dist[to]){
                    q.erase({dist[to], to});
                    dist[to] = dist[v] + len;
                    q.insert({dist[to], to});
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        adj.assign(n + 1, {});
        dist.assign(n + 1, inf);
        
        for(auto t: times){
            adj[t[0]].push_back({t[1], t[2]});
        }
        
        dijkstra(src);
        
        int mx = 0;
        for(int i = 1; i <= n; i++){
            cout << dist[i] << endl;
            if(dist[i] == inf)
                return -1;
            mx = max(mx, dist[i]);
        }
        
        return mx;
    }
};