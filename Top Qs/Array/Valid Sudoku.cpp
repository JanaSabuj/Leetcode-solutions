class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        for(int i = 0; i < n; i++){
            set<int> s;
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    if(s.find(board[i][j]) == s.end()){
                        s.insert(board[i][j]);
                    }
                else{
                    return false;
                }
                }
            }
         
        }
        
        for(int j = 0; j < n; j++){
            set<int> s;
            for(int i = 0; i < n; i++){
                if(board[i][j] != '.'){
                    if(s.find(board[i][j]) == s.end()){
                        s.insert(board[i][j]);}
                    else{
                        return false;
                    }
                }
                        
            }
       
        }
        
        vector<int> val = {0,3,6};
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                
                int x1 = val[i], y1 = val[j];
                int x2 = x1 + 2, y2 = y1 + 2;
                
                
                set<int> s;
                
                for(int k = x1; k <= x2; k++){
                    for(int c = y1; c <= y2; c++){
                        
                        if(board[k][c] != '.'){
                            if(s.find(board[k][c]) == s.end()){
                                s.insert(board[k][c]);}
                            else{
                                return false;
                            }
                        }
                        
                    }
                }
                
       
            }
        }
        
        return true;
            
    }
};