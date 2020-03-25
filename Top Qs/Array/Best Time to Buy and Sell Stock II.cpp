class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        
        for(int i = 1; i < n; i++){
            profit += max(0, prices[i] - prices[i-1]);
        }
        
        return profit;
    }
};