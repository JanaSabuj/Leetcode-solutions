class Solution {
public:
    
    enum Color{
        white,
        gray,
        black
    };
    
    int dfs(vector<vector<int>>& graph, vector<int>& color, int x){
        
        // base
        if(color[x]) 
            return color[x] == black;// safe
                
        // main
        color[x] = gray;        
        for(auto v: graph[x]){
            if(!dfs(graph, color, v))
                return false;
        }
        color[x] = black;
        return true;      
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, white);
        
        // dfs that returns safe/unsafe
        vector<int> safe;
        for(int i = 0; i < n; i++){
           if(dfs(graph, color, i))
               safe.push_back(i);
        }
        
        return safe;
    }
};
