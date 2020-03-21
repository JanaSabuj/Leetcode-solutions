class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        
        int n = A.size();
        int dp[n];
        dp[0] = A[0];

        int mx = A[0];
        for(int i = 1; i < k; i++){
        	mx = max(mx, A[i]);
        	dp[i] = mx * (i + 1);
        }

        for(int i = k; i < n; i++){
        	dp[i] = dp[i-1] + A[i];          
        	int nx = A[i];
            
        	for(int j = i - 1; j >= (i-(k-1)); j--){
        		nx = max(nx, A[j]);
        		dp[i] = max(dp[j-1] + nx * (i-j+1), dp[i]);
        	}
        }

        return dp[n-1];
    }
};
