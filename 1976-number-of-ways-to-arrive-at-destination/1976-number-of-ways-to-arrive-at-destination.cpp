using pii = pair<long long int, long long int>;
using vi = vector<long long int>;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long int mod = 1e9 + 7;
        vector<pii> adj[n + 1];
        for (auto p : roads) {
            adj[p[0]].push_back({p[1], p[2]});
            adj[p[1]].push_back({p[0], p[2]});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;// min heap
        vi dist(n + 1, LLONG_MAX);// shortest distance
        vi ways(n + 1, 0);// dp

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            long long int v = p.second;
            long long int d_v = p.first;
            if(d_v != dist[v])
                continue;

            for(auto u: adj[v]) {
                long long int to = u.first;
                long long int len = u.second;

                if(d_v + len < dist[to]) {
                    dist[to] = d_v + len;
                    pq.push({dist[to], to});
                    ways[to] = ways[v];
                }else if(d_v + len == dist[to]) {
                    ways[to] = (ways[to] + ways[v]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};
