class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1;
        int n = nums.size();
        
        int cnt = 0;
        int i = 0;// left ptr
        for(int j = 0; j < n; j++){
            // include
            prod *= nums[j];
            
            // validate
            while(i <= j and prod >= k)
                prod /= nums[i++];
            
            // i-j is the valid subarray
            cnt += (j - i + 1);
        }
        
        return cnt;
    }
};