class Solution {
public:
    double globans;
    void dfs(string x, string end,map<string, vector<pair<string,double>>>& adj, set<string>& vis, double val){
        vis.insert(x);
        if(x == end){
            globans = val;
            return;
        }
                    
        for(auto u: adj[x]){
            if(vis.count(u.first) == 0){
                dfs(u.first, end, adj, vis, 1.0 * val * u.second);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string,double>>> adj;
        int n = equations.size();
        // create graph
        for (int i = 0; i < n; ++i){
            string num = equations[i][0];
            string den = equations[i][1];
            adj[num].push_back({den, values[i] * 1.0});
            adj[den].push_back({num, 1.0 / values[i]});
        }

        // queries
        int q = queries.size();
        vector<double> ans;
        for (int i = 0; i < q; ++i){
            string num = queries[i][0];
            string den = queries[i][1];

            if(adj.find(num) == adj.end() or adj.find(den) == adj.end()){
                ans.push_back(-1.0);
                continue;
            }
            set<string> vis;
            double val = 1.0;
            globans = -1.0;
            dfs(num, den, adj, vis, val);
            ans.push_back(globans);
        }
        
        return ans;
    }
};