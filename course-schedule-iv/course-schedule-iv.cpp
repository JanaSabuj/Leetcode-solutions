class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> adj[numCourses + 1];
        vector<int> indeg(numCourses + 1, 0);
        
        for(auto& p: prerequisites){
            adj[p[0]].push_back(p[1]);
            indeg[p[1]]++;
        }

        // kahn topological
        queue<int> q;
        for (int i = 0; i < numCourses; ++i){
            if(indeg[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int v = q.front(); q.pop();
            topo.push_back(v);
            
            for(auto u: adj[v]){
                indeg[u]--;
                if(indeg[u] == 0)
                    q.push(u);
            }
        }

        vector<set<int>> dp(numCourses+1);
        int n = topo.size();
        for(int i = n - 1; i >= 0; i--){
            for(auto v: adj[topo[i]]){
                dp[topo[i]].insert(v);
                dp[topo[i]].insert(dp[v].begin(), dp[v].end());
            }
        }

        // q
        vector<bool> ans;
        for(auto& q: queries){
            ans.push_back(dp[q[0]].count(q[1]) > 0);
        }

        return ans;
    }
};