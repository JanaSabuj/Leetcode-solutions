class Solution {
public:
    
    int dp[1000][1000];
    int ED(string& A, string& B, int m, int n){
        if(m == 0)
            return n;
        if(n == 0)
            return m;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(A[m - 1] == B[n - 1])
            return dp[m][n] =  ED(A, B, m - 1, n - 1);
        
        return dp[m][n] =  1 + min({ED(A,B,m-1,n),ED(A,B,m,n - 1),ED(A,B,m-1,n - 1)});
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        memset(dp, -1, sizeof(dp));
        return ED(word1, word2, m, n);
    }
};
