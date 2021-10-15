class Solution {

public:
    void dfs(int root, int par, vector<int> adj[], int ht1[], int ht2[]) {
        
        for (auto v : adj[root]) {
            if (v != par) {
                dfs(v, root, adj, ht1, ht2);                
            }
        }
        
        int hta = -1, htb = -1;
        for(auto v: adj[root]){
            if(v != par){
                int tmp = 1 + ht1[v];
                if (tmp > hta)
                {
                    htb = hta;
                    hta = tmp;
                } else if (tmp >= htb) {
                    htb = tmp;
                }
            }
        }

        ht1[root] = max(hta, 0);
        ht2[root] = htb;       
    }
    
    void dfs2(int root, int par, vector<int> adj[], int ht1[], int ht2[], int ht3[], int acc){        
         ht3[root] = max(acc, ht1[root]);
        
         for (auto v : adj[root]) {             
            if (v != par) {
                if(1 + ht1[v] == ht1[root]){
                    dfs2(v, root, adj, ht1, ht2, ht3, max(1 + ht2[root], 1 + acc));                    
                }else {
                dfs2(v, root, adj, ht1, ht2, ht3, max(1 + ht1[root], 1 + acc));                    
                }
            }
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {        
        vector<int> adj[n];

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ht1[n], ht2[n], ht3[n];
        dfs(0, -1, adj, ht1, ht2);
        
        dfs2(0, -1, adj, ht1, ht2, ht3, 0);

        vector<int> ans;
        int mn = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            cout << ht1[i] << " " << ht2[i] << " " << ht3[i] << endl;            
            mn = min(mn, ht3[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (ht3[i] == mn)
                ans.push_back(i);
        }

        return ans;
    }
};