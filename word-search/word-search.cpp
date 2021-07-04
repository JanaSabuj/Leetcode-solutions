class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool dfs(int i, int j, int idx, const string& word, vector<vector<char>>& board){                        
        int n = board.size();
        int m = board[0].size();
        
        int len = word.size();
        if(idx == len - 1){
            return board[i][j] == word[idx];
        }
        
        if (board[i][j] != word[idx])
            return false;
        
        
        char old = board[i][j];
        board[i][j] = '0';// visited
        
        for(int k = 0; k < 4; k++){
            int r = i + dx[k];
            int c = j + dy[k];
            
            if(r < 0 or r >= n or c < 0 or c >= m or board[r][c] == '0')
                continue;
                       
            if (dfs(r, c, idx + 1, word, board))
                return true;                        
        }
        
        board[i][j] = old;// undo & backtrack
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int len = word.size();
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){                    
                    if(dfs(i, j, 0, word, board))
                        return true;
                }
            }
        }
        
        return false;
    }
};