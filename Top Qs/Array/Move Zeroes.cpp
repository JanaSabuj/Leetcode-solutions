class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int snow = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                snow++;
            else{
                int t = nums[i];
                nums[i] = 0;
                nums[i-snow] = t;
            }
        }
        
        
    }
};