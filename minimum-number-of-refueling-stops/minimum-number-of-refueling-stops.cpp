class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // dp[i] = max dist you can go using i stops
        int n = stations.size();
        vector<long long int> dp(n+1,0);
        dp[0] = startFuel;
        
        // for each station limit
        for(int i = 0; i < n; i++){
            for(int t = i; t >= 0; t--){
                if(dp[t] >= stations[i][0]){
                    dp[t+1] = max(dp[t+1], dp[t] + stations[i][1]);
                }
            }    
        }
        
        for(int i = 0; i <= n; i++){
            if(dp[i] >= target)
                return i;
        }
        
        return -1;
    }
};