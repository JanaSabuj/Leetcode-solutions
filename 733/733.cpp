class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool valid(int r, int c, int n, int m){
        return (r >= 0 and r < n and c >= 0 and c < m);
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int n, int m, int nc, vector<int>& visited){
        int col = image[sr][sc];
        image[sr][sc] = nc;
        visited[sr * m + sc] = 1;
        
        for(int i = 0; i < 4; i++){
            int r = sr + dx[i];
            int c = sc + dy[i];
            
            if(valid(r, c, n, m) and image[r][c] == col and !visited[r * m + c])
                dfs(image, r, c, n, m, nc, visited);
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<int> visited(n * m, 0);
        
        dfs(image, sr, sc, n, m, newColor, visited);
        return image;
    }
};
