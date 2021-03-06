class Solution {
public:
    pair<int,int> func(int x, int n){
        int r = x / n;
        int c = x % n;
        
        int row = n - 1 - r;
        int col = (r % 2 == 0) ? c : (n - 1 - c);
        
        return {row,col};        
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        
        queue<int> q;
        vector<int> visited(n * n + 1, 0);
        
        q.push(1);
        visited[1] = 1;
        
        int steps = -1;
                
        while(!q.empty()){            
            int sz = q.size();            
            steps++;
            
            while(sz--){                            
                int x = q.front();
                q.pop();
                
                if(x == n * n)
                    return steps;

                for(int i = 1; i <= 6; i++){
                    int v = x + i;
                    if(v > n * n) break;                                                                            
                        pair<int,int> c = func(v - 1, n);
                        int a = c.first, b = c.second;
                    
                        if(board[a][b] == -1){
                            if(!visited[v]){
                                q.push(v);
                                visited[v] = 1;
                            }
                        }
                    
                        else{                        
                            if(!visited[board[a][b]]){
                                q.push(board[a][b]);
                                visited[board[a][b]] = 1;
                                // visited[v] = 1;
                            }
                        }
                    
                }
            }
        }
        
        return -1;
    }
};
