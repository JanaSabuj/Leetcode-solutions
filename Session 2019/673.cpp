class Solution {
public:
    int LIS(const vector<int>& arr){
        int n = arr.size();
        if(n == 0)
            return 0;
        vector<pair<int,int>> dp(n, {1,1});// len,cnt
        
        int mxlen = 0;
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i]){
                    if(dp[j].first + 1 == dp[i].first)
                        dp[i].second += dp[j].second;
                    else if(dp[j].first + 1 > dp[i].first){
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    }
                }
                
            }
            
            if(dp[i].first == mxlen)
                cnt += dp[i].second;
            else if(dp[i].first > mxlen){
                mxlen = dp[i].first;
                cnt = dp[i].second;
            }
            
        }
        
  
        return cnt;
    }
    
    int findNumberOfLIS(vector<int>& nums) {
        return LIS(nums);
    }
};
