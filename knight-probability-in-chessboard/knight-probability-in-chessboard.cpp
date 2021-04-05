class Solution {
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1 ,-1, 1, -1};
    double dp[105][30][30];
public:
    double knightProbability(int N, int K, int r, int c) {
        for(int i = 0; i < 105; i++)
            for(int j = 0; j < 30; j++)
                for(int k = 0; k < 30; k++)
                    dp[i][j][k] = -1.0;
        return find(N, K, r, c);
    }
    
    double find(int N, int K, int r, int c){
        if(!valid(r, c, N)) return 0;
        if(K == 0) return 1;
        
        if(dp[K][r][c] != -1.0)
            return dp[K][r][c];
        
        double prob = 0.0;
        for(int i = 0; i < 8; i++){
            prob += find(N, K - 1, r + dx[i], c + dy[i]) / 8.0;
        }
        return dp[K][r][c] = prob;
    }
    
    bool valid(int r, int c, int N){
        return (r >= 0 and r < N and c >= 0 and c < N);
    }
};