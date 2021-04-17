class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = 1;
        
        for(int i = 1; i < n; i++){
            bool isSelfI = A[i - 1] < A[i] and B[i - 1] < B[i];
            bool isOppI = A[i - 1] < B[i] and B[i - 1] < A[i];
            
            if(isSelfI and isOppI){
                dp[i][0] = min(dp[i-1][0], dp[i-1][1]);                                
                dp[i][1] = min(dp[i-1][0], dp[i - 1][1]) + 1;
            }else if(isSelfI){
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + 1;
            }else if(isOppI){
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][0] + 1;
            }
        }
        
        return min(dp[n-1][0], dp[n-1][1]);
    }
};
