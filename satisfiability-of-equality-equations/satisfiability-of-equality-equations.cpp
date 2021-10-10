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

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        dsu G;
        G._init(27*2);

        for(auto e :equations){
            int a = e[0] - 'a';
            int b = e[3] - 'a';

            if(e[1] == '='){                
                G.union_sets(a, b);
            }
        }
        
        for(auto e :equations){
            int a = e[0] - 'a';
            int b = e[3] - 'a';

            if(e[1] == '!'){       
                if(G.find_set(a) == G.find_set(b)) return false;                
            }
        }

        return true;
    }
};