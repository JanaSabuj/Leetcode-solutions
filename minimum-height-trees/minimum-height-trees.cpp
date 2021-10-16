typedef vector<int> vi;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        
        vi adj[n];
        vi indeg(n,0);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
            indeg[e[1]]++;
        }

        // topo - kahn's
        queue<int> q;
        for (int i = 0; i < n; ++i){
            if(indeg[i] == 1)
                q.push(i);
        }

        vi ans;
        while(!q.empty()){
            int sz = q.size();
            ans.clear();
            while(sz--){
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(auto v: adj[curr]){
                    indeg[v]--;
                    if(indeg[v] == 1)
                        q.push(v);
                }
            }
        }

        return ans;
    }
};