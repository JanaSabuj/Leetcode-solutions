typedef vector<int> vi;

class Solution {
    vector<int> parent;
    vector<int> _size;
public:
    int find_set(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find_set(parent[x]);
    }
    
    void union_(int a, int b, int& comp){
        a = find_set(a);
        b = find_set(b);
        
        if(a != b){
            if(_size[a] < _size[b])
                swap(a,b);
            
            parent[b] = a;
            _size[a] += _size[b];
            comp--;
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        
        parent.assign(n, 0);
        _size.assign(n, 0);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
            _size[i] = 1;
        }
        
        int comp = n;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j] == 1){
                    // i - j is an edge
                    union_(i, j, comp);
                }
            }
        }
        
        return comp;
    }
};