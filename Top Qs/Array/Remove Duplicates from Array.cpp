class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 or n == 1)
            return n;
        int i = 0, j = 1;
        while(j < n){
            if(nums[i] == nums[j])
                j++;
            else{
                i++;
                //swap
                int t = nums[i];nums[i]=nums[j];nums[j]=t;
                j++;
            }
        }
        
        return i+1;
    }
};