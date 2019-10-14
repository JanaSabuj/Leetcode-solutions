class Solution {
public:
    int missingNumber(vector<int>& nums) {
             
        int sum = 0;        
        int n = nums.size();
        
        for(auto x:nums){
            sum += x;        
        }
        
        int total = (n*(n+1)) / 2;      
        int rem = total - sum;
        
        return rem;
        
    }
};