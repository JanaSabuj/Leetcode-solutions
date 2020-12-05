class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int v = prices[0], p = prices[0];
        int i = 0;
        int prof=0;
        while(i < n - 1){
            while(i < n - 1 and prices[i] >= prices[i+1])
                i++;
            v = prices[i];// buy
            
            while(i < n - 1 and prices[i] <= prices[i+1])
                i++;
            p = prices[i];// sell
            prof += (p - v);
        }
        
        return prof;
    }
};
