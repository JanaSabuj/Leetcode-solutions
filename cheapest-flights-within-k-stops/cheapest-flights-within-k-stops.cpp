using vi = vector<int>;
using pii = pair<int,int>;
class Solution {
    const int inf = 1e9;
    vector<vector<pii>> adj;
    vector<int> d, stops;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        K++;
        adj.assign(n, {});
        d.assign(n, inf);
        stops.assign(n, -1);
        
        for(auto edge: flights){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        pq.push({0, 0, src}); // (dist, stops, vertex)                
        
        while(!pq.empty()){
            int v = pq.top()[2];
            int d_v = pq.top()[0];
            int st_v = pq.top()[1];
            pq.pop();            
            
            cout <<"reac" << v << "-" <<  endl;
            if(v == dst){
                return d_v;
            }
            
            for(auto edge: adj[v]){
                int to = edge.first;
                int len = edge.second;
                
                if(st_v + 1 <= K){                                        
                    pq.push({d_v + len, st_v + 1,to});
                }
            }
        }
        
        return -1;
    }
};