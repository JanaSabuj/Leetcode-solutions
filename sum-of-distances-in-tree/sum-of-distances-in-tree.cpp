class Solution {
    const static int N = 1e4 + 7;
    vector<int> adj[N];
    int ans1[N], ans[N], nodes[N];
public:
    void dfs1(int node, int par) {
        for (auto to : adj[node]) {
            if (to != par) {
                dfs1(to, node);
                nodes[node] += nodes[to];
                ans1[node] += (ans1[to] + nodes[to]);
            }
        }

        nodes[node]++;
    }

    void dfs2(int node, int par, int to_p) {
        ans[node] = ans1[node] + to_p + (nodes[0] - nodes[node]); // include the linkage
        for (auto to : adj[node]) {
            if (to != par) {
                dfs2(to, node, ans[node] - (ans1[to] + nodes[to]));
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for (auto v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        // dfs1
        dfs1(0, -1);

        // dfs2
        dfs2(0, -1, 0);

        // result
        vector<int> ansF;
        for (int i = 0; i < n; i++) {
            ansF.push_back(ans[i]);
        }

        return ansF;
    }
};