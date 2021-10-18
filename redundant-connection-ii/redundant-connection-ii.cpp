typedef vector<int> vi;

struct dsu {
    vector<int> parent;
    vector<int> _size;

    // merge two sets having a&b as entities
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (_size[a] < _size[b])
                swap(a, b);
            parent[b] = a;
            _size[a] += _size[b];
        }
    }

    // find the set leader
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    // check if same set/leader
    bool same_comp(int a, int b) {
        return find_set(a) == find_set(b);
    }

    void make_set(int v) {
        parent[v] = v;
        _size[v] = 1;
    }

    void _init(int n) {
        parent.assign(n, 0);
        _size.assign(n, 0);

        for (int i = 0; i < n; i++)
            make_set(i);
    }
};

class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int edgeParent = -1;
        int edgeCycle = -1;

        int n = edges.size();

        // 1. check for dual parent edge
        vi par(n + 1, 0);
        for (int i = 0; i < n; i++) {
            auto e = edges[i];
            int a = e[0];
            int b = e[1];
            // a -> b            
            if (par[b])
            {
                // c -> b
                edgeParent = i;
                break;
            }
            else {
                par[b] = a;
            }
        }

        // 2. check for cycle after removing the dual parent edge
        dsu G;
        G._init(n + 1);
        for (int i = 0; i < n; ++i) {
            if (i == edgeParent) continue;
            auto e = edges[i];
            int a = e[0];
            int b = e[1];

            if (G.find_set(a) != G.find_set(b))
                G.union_sets(a, b);
            else {
                edgeCycle = i;
                break;
            }
        }

        // if no 2nd parent, 
        if(edgeParent == -1){
            return edges[edgeCycle];
        }

        // if 2nd parent, but the wrong edge
        if(edgeCycle != -1){
            int to = edges[edgeParent][1];
            int p = par[to];
            return {p, to};
        }

        // the correct 2nd edge
        return edges[edgeParent];
    }
};
