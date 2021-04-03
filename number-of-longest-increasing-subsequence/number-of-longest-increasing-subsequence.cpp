class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), cnt(n, 1);
        
        int mxlen = 1;
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    if(lis[j] + 1 > lis[i]){
                        lis[i] = lis[j] + 1;
                        cnt[i] = cnt[j];
                    }else if(lis[j] + 1 == lis[i])
                        cnt[i] += cnt[j];
                }                    
            }
            
            mxlen = max(mxlen, lis[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){                            
            if(lis[i] == mxlen)
                ans += cnt[i];
        }
        
        return ans;
    }
};
