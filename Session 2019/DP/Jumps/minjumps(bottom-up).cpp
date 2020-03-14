#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;

    while(test--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        
        vector<int> dp(n);
        // dp[i] = min no of steps to reach end from i
        for(int i = n - 1; i >= 0; i--){
            if(i == n-1)
                dp[i] = 0;
            else if(arr[i] >= (n - 1 - i))
                dp[i] = 1;
            else if(arr[i] == 0)
                dp[i] = INT_MAX;
            else{
                int d = arr[i];
                int steps = INT_MAX;

                for(int k = 1; k <= d and k + i < n; k++){
                    steps =  min(steps, dp[k + i]);   
                }

                if(steps == INT_MAX)
                    dp[i] = INT_MAX;
                else
                    dp[i] = 1 + steps;
            }
        }
       cout << (dp[0] == INT_MAX ? -1 : dp[0]) << endl;
    }
    return 0;
}
