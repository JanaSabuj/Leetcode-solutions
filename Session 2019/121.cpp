class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // maintain a right-max  
        
        int n = prices.size(); 
        if(n==0)
            return 0;
        int dp[n];// maxR
        int ans = prices[n-1];
        
        for(int i=n-1; i>=0; i--){
            ans = max(ans,prices[i]);
            dp[i] = ans;
        }
        
        int profit = 0;
        for(int i=0; i<n; i++){
            profit = max(profit, dp[i] - prices[i]);
        }
        
        return profit;
    }
};