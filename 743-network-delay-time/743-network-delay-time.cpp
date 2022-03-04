// https://leetcode.com/problems/network-delay-time/
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto p: times) {
            adj[p[0]].push_back({p[1], p[2]});
        }
        
        vi dist(n + 1, INT_MAX);
        dijkstra(adj, dist, k, n);
        

        int mx = 0;
        for (int i = 1; i <= n; ++i){
            if(dist[i] == INT_MAX) {
                return -1;                
            }
            mx = max(mx, dist[i]);
        }

        return mx;
    }

    void dijkstra(vector<vector<pair<int,int>>>& adj, vi& dist, int src, int n) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            int v = pq.top().second;
            int d_v = pq.top().first;
            pq.pop();

            if (d_v != dist[v])
                continue;

            // v -> u
            for(auto u: adj[v]) {
                int to = u.first;
                int len = u.second;

                if(dist[v] + len < dist[to]) {
                    dist[to] = dist[v] + len;
                    pq.push({dist[to], to});
                }
            }
        }        
    }
};

