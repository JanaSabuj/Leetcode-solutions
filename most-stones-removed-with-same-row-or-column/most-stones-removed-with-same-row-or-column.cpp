struct dsu {
    vector<int> parent;
    vector<int> sz;

    void _init(int x){
        parent.assign(x, 0);
        sz.assign(x,0);

        for (int i = 0; i < x; ++i){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find_set(int x){
        if(x == parent[x])
            return x;
        return parent[x] = find_set(parent[x]);
    }

    void _union(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if(sz[a] < sz[b])
            swap(a,b);

        parent[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        dsu G;
        G._init(n+1);

        map<int, vector<int>> rowmap, colmap;
        for (int i = 0; i < n; ++i){
            rowmap[stones[i][0]].push_back(i);
            colmap[stones[i][1]].push_back(i);
        }

        int nodes = n;
        for (int i = 0; i < n; ++i){
            for(auto j: rowmap[stones[i][0]]){
                if(G.find_set(i) != G.find_set(j)){
                    G._union(i, j);
                    nodes--;
                }
            }

            for(auto j: colmap[stones[i][1]]){
                if(G.find_set(i) != G.find_set(j)){
                    G._union(i, j);
                    nodes--;
                }
            }
        }

        return n - nodes;
    }
};