class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(N + 1);
        for(auto edge: dislikes){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

        }
        
        vector<int> color(N+1 , -1);
        bool ans = true;
        for(int i = 1; i <= N; i++){
            if(color[i] == -1){
                // bfs
                queue<int> q;
                q.push(i);
                color[i] = 1;
                
                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    
                    for(auto u: adj[v]){
                        if(color[u] == -1){
                            color[u] = color[v] ^ 1;
                            q.push(u);
                        }else{
                            ans = ans & !(color[u] == color[v]);    
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
