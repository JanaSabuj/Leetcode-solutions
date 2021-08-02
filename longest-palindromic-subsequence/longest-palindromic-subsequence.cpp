class Solution {
public:
    int longestPalindromeSubseq(string str) {
        int n = str.size();
        
        int dp[n][n];
        // dp[i][j] - str[i..j] 
        
        // len1
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        // len2
        for(int i = 0; i < n - 1; i++)
            dp[i][i+1] = (str[i] == str[i+1] ? 2 : 1);
        
        // len3 - n
        for(int l = 3; l <= n; l++){
            for(int i = 0; i <= n - l; i++){
                int j = i + l - 1;
                
                if(str[i] == str[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        return dp[0][n-1];        
    }
};