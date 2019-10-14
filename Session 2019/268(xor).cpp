class Solution {
public:
    int missingNumber(vector<int>& nums) {
     
        int n = nums.size();
        
        int tmp = n;
        
        for(int i=0; i<n; i++){
           tmp = tmp^i;
            tmp = tmp^nums[i]; 
        }
        
        return tmp;
        
    }
};