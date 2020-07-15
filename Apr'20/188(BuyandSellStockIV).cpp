class Solution {
public:
    int normal(vector<int>& prices){
        int sum = 0;
        for(int i = 1; i < (int)prices.size(); i++){
            sum += max(0, prices[i] - prices[i - 1]);
        }
        
        return sum;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;    
        
        if(k >= n/2)
            return normal(prices);
        
        int profits[2][n];
        memset(profits, 0, sizeof(profits));
        
        int curr = 1;
        for(int t = 1; t <= k; t++, curr = !curr){            
            int maxProf = INT_MIN;
            for(int d = 1; d < n; d++){                
                maxProf = max(maxProf, -prices[d - 1] + profits[!curr][d - 1]);
                profits[curr][d] = max(profits[curr][d - 1], prices[d] + maxProf);
            }
        }
        
        return profits[!curr][n - 1];
    }
};
