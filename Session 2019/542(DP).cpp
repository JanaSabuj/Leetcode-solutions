class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int r = mat.size();
        int c = mat[0].size();
        
        vector<vector<int>> out(r, vector<int>(c,INT_MAX - 10000));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] == 0)
                    out[i][j] = 0;
                else{
                    if(i > 0)
                        out[i][j] = min(out[i][j], out[i - 1][j] + 1);
                    if(j > 0)
                        out[i][j] = min(out[i][j], out[i][j - 1] + 1);
                }
                    
            }
        }
        
        
        for(int i = r -1; i >=0; i--){
            for(int j = c - 1; j >=0; j--){
                if(mat[i][j] == 0)
                    out[i][j] = 0;
                else{
                    if(i < r - 1)
                        out[i][j] = min(out[i][j], out[i + 1][j] + 1);
                    if(j < c - 1)
                        out[i][j] = min(out[i][j], out[i][j + 1] + 1);
                }
            }
        }
        
        return out;
    }
};