743. Network Delay Time
Medium

1021

201

Add to List

Share
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
Accepted
65,039
Submissions
143,821

-------------------------------------------------------------
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> adj(N+1);
        for(auto vec: times){
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        
        int dist[N+1];
        for(int i = 1; i <= N; i++)
            dist[i] = INT_MAX;
        dist[K] = 0;
        
        dijkstra(adj,dist,N,K);
        
        int ans = -1;
        for(int i = 1; i <= N; i++){
            if(dist[i] == INT_MAX)
                return -1;
            ans = max(ans,dist[i]);
        }
        
        return ans;
    }
    
    void dijkstra(const vector<vector<pair<int,int>>>& adj, int dist[], int N, int K){
        bool visited[N+1];
        memset(visited, false, sizeof(visited));
        
        for(int i = 1; i <= N; i++){
            int u = getMV(adj,dist,visited,N);
            visited[u] = true;
            
            for(auto edge: adj[u]){
                int v = edge.first;
                int wt = edge.second;
                
                if(!visited[v])
                    if(dist[u] + wt < dist[v])
                        dist[v] = dist[u] + wt;
            }
        }
    }
    
    int getMV(const vector<vector<pair<int,int>>>& adj, int dist[], bool visited[], int N){
        int mv = -1;
        for(int i = 1; i <= N; i++){
            if(!visited[i] and (mv == -1 or dist[i] < dist[mv]))
                mv = i;
        }
        
        return mv;
    }
    

};