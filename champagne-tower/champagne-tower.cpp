class Solution {
public:
    double champagneTower(int poured, int qr, int qc) {
        double A[qr + 2][qc + 2];
        memset(A, 0, sizeof(A));
        
        A[0][0] = poured;
        for(int i = 0; i <= qr; i++){
            for(int j = 0; j <= qc; j++){
                double nxt = (double)(A[i][j] - 1.0)/2.0;
                
                if(nxt > 0){
                    A[i+1][j] += nxt;
                    A[i+1][j+1] += nxt;
                }
                                
            }
        }
        
        return min(1.0, A[qr][qc]);
    }
};
