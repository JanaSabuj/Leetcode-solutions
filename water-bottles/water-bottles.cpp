class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int a = numBottles;
        int b = 0;
        int k = numExchange;
        
        int ans = 0;
        while(a != 0){
            ans += a;
            
            b = b + a;
            a = b/k;
            b = b%k;
        }
        
        return ans;
    }
};
