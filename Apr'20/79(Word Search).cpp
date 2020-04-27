class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool dfs(int i, int j, int idx, int len, const vector<vector<char>>& board, const string& word, bool visited[], int n, int m){
        if(idx == len - 1){
            return board[i][j] == word[idx];
        }
        
        if(board[i][j] != word[idx])
            return false;
        cout << board[i][j] << " " << i << " " << j << " " <<  idx << " " << word[idx] << endl;
        
         visited[i * m + j] = true;
        
        for(int k = 0; k < 4; k++){
            int r = i + dx[k];
            int c = j + dy[k];
            
            if(r < 0 or r >= n or c < 0 or c >= m or visited[r * m + c])
                continue;
            
           
            if (dfs(r, c, idx + 1, len, board, word, visited, n, m))
                return true;
            
            
        }
        
       visited[i * m + j] = false;
        
        return false;   
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int len = word.size();
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    cout << i << " " << j << endl;
                    bool visited[n*m];
                    memset(visited, false, sizeof(visited));
                    
                    if(dfs(i, j, 0, len, board, word, visited, n, m))
                        return true;
                }
            }
        }
        
        return false;
    }
};
