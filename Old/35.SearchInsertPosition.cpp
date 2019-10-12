class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int sz=nums.size();
        int low=0;
        int high=sz-1;
        int expected;
        while(low<=high){
            
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(target>nums[mid]){
                low=mid+1;
                expected=low;
            }
            else{
                high=mid-1;
                expected=mid;
            }
             
        }
        
        return expected;
         
    }
};