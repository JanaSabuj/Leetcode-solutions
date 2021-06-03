class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // the req subarray will end at some index i, so max till i

        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        int ans = 0;        
        int imax = 0;
        int imin = 0;
        
        for(int i = 0; i < n; i++){             
            
            if(nums[i] < 0)
                swap(imax, imin);
            
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]); 
            
            ans = max(ans, imax);
        }
        
        return ans;
    }
    
    
};