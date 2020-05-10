class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        int isCol = -1;
        int isRow = -1;
        
        int n = A.size();
        int m = A[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(A[i][j] == 0){
                    if(i == 0)
                        isRow = 0;
                    else
                        A[i][0] = 0;
                    
                    if(j == 0)
                        isCol = 0;
                    else
                        A[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(A[i][0] == 0 or A[0][j] == 0)
                    A[i][j] = 0;
            }
        }
        
        if(isRow == 0)
            for(int j = 0; j <m; j++)
                A[0][j] = 0;
        
        if(isCol == 0)
            for(int i = 0; i < n; i++)
                A[i][0] = 0;
        
    }
};
