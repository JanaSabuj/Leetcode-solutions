class Solution {
public:
     int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0}; 
    
    bool valid(int r, int c, int n, int m){
        return (r >= 0 and r < n and c >= 0 and c < m);
    }
    
    void dfs(vector<vector<int>>& board, int x, int y, int n, int m){
        board[x][y] = 2;
        for(int i = 0; i < 4; i++){
            int r = x + dx[i];
            int c = y + dy[i];
            
            if(valid(r,c,n,m) and board[r][c] == 1)
                dfs(board, r, c, n, m);                
        }        
    }  
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        if(n == 0)
            return 0;
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 1)
                    if(i == 0 or i == n-1 or j == 0 or j == m-1){
                        dfs(board, i, j, n, m);
                    }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 1)                    
                    cnt++;
            }     
        }
        
        return cnt;
    }
};
