class Solution {
public:
    
    int isSafe(int i, int j, int n, int m){
        if(i<0 or i>=n or j<0 or j>=m)
            return 0;
        return 1;
    }
    
    int val(int i,int j,vector<vector<int>>& grid){
        
        // cout << i <<" " << j <<endl;
        if(grid[i][j]==0)
            return 1;
        else
            return 0;
    }
    
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int cnt=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0; i<(int)grid.size(); i++){
            
            for(int j=0; j<(int)grid[i].size(); j++){
                
                //left
                if(grid[i][j] == 1)
              {  
                    if(isSafe(i,j-1,n,m))
                    cnt += (grid[i][j-1] == 0) ? 1 : 0 ;
                else
                    cnt++;
                    //right
                if(isSafe(i,j+1,n,m))
                    cnt += val(i,j+1,grid);
                else
                    cnt++;
                    //top
                if(isSafe(i-1,j,n,m))
                    cnt += val(i-1,j,grid);
                else
                    cnt++;
                    //bottom
                if(isSafe(i+1,j,n,m))
                    cnt += val(i+1,j,grid);
                else
                    cnt++;
                
                }
                
                
            }
            
            
        }
        
        return cnt;
        
        
    }
};