class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> deg(n + 2, 0);
        
        for(auto& v: edges){
            deg[v[0]]++;
            deg[v[1]]++;
            
            if(deg[v[0]] == n)
                return v[0];
            if(deg[v[1]] == n)
                return v[1];
        }
        
        return -1;
    }
};