class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nxt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[nxt] = nums[i];
                nxt++;
            }                
        }
        
        for(int i = nxt; i < n; i++){
            nums[i] = 0;
        }
    }
};
