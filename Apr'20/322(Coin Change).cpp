class Solution {
    vector<int> arr;
 int len, total;
int possible;
    int dp[100][10000];
public:
    
    
    int minCoins( int idx, int store) {
    if (store < 0)
        return total;// invalid config returns MAX coins
    if (idx == len) {
        if (store == 0) {
            possible = true;
            return 0;
        } else {
            return total;// invalid config returns MAX coins
        }
    }

    if (dp[idx][store] != -1)
        return dp[idx][store];

 int A = 1 + minCoins(idx, store - arr[idx]);
 int B = minCoins(idx + 1, store);

    return dp[idx][store] =  min(A, B);
}
     int coinChange(vector<int>& coins, int amount) {
        arr = coins;
        total = amount;
        len = coins.size();
        possible = false;
         memset(dp, -1, sizeof(dp));
     int val = minCoins(0, total);
        
        if(possible)
            return val;
        else
            return -1;
            
    }
};
