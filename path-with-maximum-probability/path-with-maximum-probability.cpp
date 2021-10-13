class Solution {
public:
    void dijkstra(int s, int e, vector<pair<int, double>> adj[], vector<double>& dist) {
        dist[s] = 0.0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({0.0, s});

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int v = curr.second;
            double d_v = curr.first;
            if (d_v > dist[v])
                continue;// stale pair
            
            if(v == e)
                break;
            
            for (auto& u : adj[v]) {
                int to = u.first;
                double len = u.second;

                if (dist[v] + len < dist[to]) {
                    dist[to] = dist[v] + len;
                    pq.push({dist[to], to});
                }
            }
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        int i = -1;
        for (auto& e : edges) {
            i++;
            adj[e[0]].push_back({e[1], -1 * log10(succProb[i])});
            adj[e[1]].push_back({e[0], -1 * log10(succProb[i])});
        }

        // dijkstra
        vector<double> dist(n, INT_MAX);
        dijkstra(start, end, adj, dist);

        if (dist[end] == INT_MAX)
            return 0;

        // double val = 0;
                double val = pow(10, -1 * dist[end]);

        return val;
    }
};