class Solution {
    
public:
    int visited[3000];
    int row, col;
    int c;
    int orig;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void dfs(int i, int j, vector<vector<int>>& image){
        visited[i * col + j] = true;
        image[i][j] = c;
        
        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x < 0 or x >= row or y < 0 or y >= col or image[x][y] != orig or visited[x * col + y] == true)
                continue;
            dfs(x, y, image);
        }
    
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        row = image.size();
        col = image[0].size();        
        memset(visited, 0, sizeof(visited));
        c = newColor;
        orig = image[sr][sc];
        
        dfs(sr, sc, image);
        return image;
    }
};
