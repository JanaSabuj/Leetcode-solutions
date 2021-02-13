class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0}; 
    
    bool valid(int r, int c, int n, int m){
        return (r >= 0 and r < n and c >= 0 and c < m);
    }
    
    void dfs(vector<vector<char>>& board, int x, int y, int n, int m){
        board[x][y] = '#';
        for(int i = 0; i < 4; i++){
            int r = x + dx[i];
            int c = y + dy[i];
            
            if(valid(r,c,n,m) and board[r][c] == 'O')
                dfs(board, r, c, n, m);                
        }        
    }  
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0)
            return;
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')
                    if(i == 0 or i == n-1 or j == 0 or j == m-1){
                        dfs(board, i, j, n, m);
                    }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '#')                    
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
                
    }
};
