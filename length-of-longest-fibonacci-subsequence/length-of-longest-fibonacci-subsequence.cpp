class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        // dp[j][k] = dp[i][j] + 1 if A[i] + A[j] == A[k]      
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0;i < n; i++)
            mp[arr[i]] = i;
        
        int dp[n][n];
        memset(dp, -1, sizeof(dp));

        int mx = 0;
        for(int k = 0; k < n; k++) {
            for(int j = 0; j < k; j++) {
                int ai = arr[k] - arr[j];
                if(mp.find(ai) == mp.end()) continue;
                int i = mp[ai];

                if(i >= 0 and i < j)
                    dp[j][k] = (dp[i][j] == -1 ? 2 : dp[i][j]) + 1;
                mx = max(mx, dp[j][k]);
            }
        }

        return (mx >= 3) ? mx : 0;
    }
};