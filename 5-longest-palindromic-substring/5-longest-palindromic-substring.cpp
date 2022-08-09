class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size();
        int dp[n][n];// dp[i][j] = 1 if str[i][j] is a palindrome
                    //           = 0, otherwise

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }

        // 1 len
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // 2 len
        for(int i = 0; i < n-1; i++) {
            dp[i][i+1] = (str[i] == str[i+1]) ? 1 : 0;
        }

        // >= 3 len
        for(int l = 3; l <= n; l++) {
            for(int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                // i-j
                if(str[i] == str[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                } else
                    dp[i][j] = 0;
            }
        }

        // find lps
        int sz = 0;
        int start = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] and (j-i+1) > sz) {
                    sz = j - i + 1;
                    start = i;
                }
            }
        }

        return str.substr(start, sz);
    }
};