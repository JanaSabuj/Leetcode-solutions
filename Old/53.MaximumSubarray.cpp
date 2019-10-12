class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans=INT_MIN,max_ending_here=0,start=0,end=0,s=0;
        int sz=nums.size();
        
        for(int i=0; i<sz; i++){
            
             max_ending_here+=nums[i];
            if(ans<max_ending_here){
                ans=max_ending_here;
                start=s;
                end=i;
            }
            
            if(max_ending_here<0){
                max_ending_here=0;
                s=i+1;
            }
            
        }
        
        return ans;
        
    }
};