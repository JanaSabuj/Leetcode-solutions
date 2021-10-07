class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n + 1];
        set<pair<int, int>> st;

        for (auto c : connections) {
            st.insert({c[0], c[1]});
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int rever = 0;

        while(!q.empty()){
            int v = q.front(); q.pop();

            for(auto u: adj[v]){
                if(!vis[u]){
                    q.push(u);
                    vis[u] = 1;
                    if(st.count({v,u}))
                        rever++;
                }
            }
        }

        return rever;
    }
};