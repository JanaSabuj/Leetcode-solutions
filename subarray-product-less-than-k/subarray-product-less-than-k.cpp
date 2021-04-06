class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int prod = 1;
        int cnt = 0;
        
        for(int i = 0, j = 0; j < n; j++){
            prod *= nums[j];
            // validate the prod
            while(i <= j and prod >= k)
                prod /= nums[i++];
            cnt += j - i + 1;
        }
        
        return cnt;
    }
};