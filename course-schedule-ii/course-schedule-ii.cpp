typedef vector<int> vi;
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vi adj[n + 1];
        vi indeg(n+1,0);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if(indeg[i] == 0)
                q.push(i);
        }

        vi topo;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            topo.push_back(x);

            for(auto v: adj[x]){
                indeg[v]--;
                if(indeg[v] == 0)
                    q.push(v);
            }
        }

        if((int)topo.size() == n)
            return topo;

        return {};
    }
};