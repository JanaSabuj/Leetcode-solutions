class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int mx = 0;
        
        for(int i = 0; i < n; i++){
            // row
            vector<int> flip;            
            for(int j = 0; j < m; j++){
                flip.push_back(matrix[i][j] ^ 1);
            }
            
            int cnt = 0;
            for(int k = i; k < n; k++){
                if(matrix[k] == flip or matrix[k] == matrix[i])
                    cnt++;
            }
            
            mx = max(mx, cnt);
        }
        
        return mx;
    }
};
