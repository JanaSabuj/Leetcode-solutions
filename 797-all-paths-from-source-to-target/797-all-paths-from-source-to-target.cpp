using vi = vector<int>;
using vvi = vector<vector<int>>;
class Solution {
    vvi ans;
    vi curr_stack;
public:
    void dfs(int x, int dest, vvi& graph) {
        curr_stack.push_back(x);

        if(x == dest) {
            ans.push_back(curr_stack);
            curr_stack.pop_back();
            return;
        }

        for(auto v: graph[x]) {
            dfs(v, dest, graph);
        }

        curr_stack.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int n = graph.size();
        int dest = n - 1;

        ans.clear();
        curr_stack.clear();

        dfs(src, dest, graph);
        return ans;
    }
};