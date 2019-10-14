 class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sz=nums.size();
        int sum=0,ans=INT_MIN;
        for(int i=0; i<sz; i++){
            sum+=nums[i];
             if(sum>ans)
                ans=sum;
            if(sum<0)
                sum=0;
            
           
        }
        
        
        return ans;
        
    }
};