struct dsu {
    vector<int> parent;

    void _union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        
        if(a != b) {        
            parent[b] = a;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);// union by path compression
    }

    void _init(int n) {
        parent.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string str, vector<vector<int>>& pairs) {

        int n = str.size();
        dsu G;
        G._init(n+2);

        // create the groups
        for(auto& p: pairs) {
            G._union(p[0], p[1]);
        }

        // collate the groups by leader
        map<int, vector<int>> grps;// leader - [nodes]
        for(int i = 0; i < n; i++) {
            grps[G.find_set(i)].push_back(i);// sorted already
        }

        // sort each group
        for(auto& g: grps) {
            string tmp = "";
            for(auto idx: g.second) tmp += str[idx];
            sort(tmp.begin(), tmp.end());

            int j = 0;
            for(auto idx: g.second)
                str[idx] = tmp[j++];
        }

        return str;
    }
};