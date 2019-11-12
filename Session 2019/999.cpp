class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size();// take n = 8
        if(n==0) return 0;
        int m = board[0].size();// take n = 8
        if(m==0) return 0;
        
        int x,y;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'R'){
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        
        int cnt = 0;
        
        for(int j = y + 1; j < m; j++){
            if(board[x][j] == '.')
                continue;
            if(board[x][j] == 'p'){
                cnt++;
                break;
            }else{
                break;
            }
        } 
        
        for(int j = y - 1; j >=0; j--){
            if(board[x][j] == '.')
                continue;
            if(board[x][j] == 'p'){
                cnt++;
                break;
            }else{
                break;
            }
        } 
        
        for(int j = x + 1; j < n; j++){
            if(board[j][y] == '.')
                continue;
            if(board[j][y] == 'p'){
                cnt++;
                break;
            }else{
                break;
            }
        } 
        
        for(int j = x - 1; j >= 0; j--){
            if(board[j][y] == '.')
                continue;
            if(board[j][y] == 'p'){
                cnt++;
                break;
            }else{
                break;
            }
        }
        
        return cnt;
        
        
    }
};
