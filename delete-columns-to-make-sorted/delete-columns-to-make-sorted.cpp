class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        
        int cnt = 0;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(i != 0 and A[i][j] < A[i - 1][j]){
                    cnt++;
                    break;
                }
            }                            
        }
        
        return cnt;
    }
};
