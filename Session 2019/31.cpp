class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pv = -1;
        int val;
        
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                pv = i;
                val = nums[i];
                break;
            }
        }
        
        if(pv == -1){
            // last stage
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i = n-1; i >= 0; i--){
            if(nums[i] > val){                
                int x = nums[i];
                nums[i] = nums[pv];
                nums[pv] = x;
                break;
            }
        }
        
       
        
        reverse(nums.begin() + pv + 1, nums.end());
        
    }
};
