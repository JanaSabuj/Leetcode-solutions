 class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        int jumps[n];
        for(int i=0; i<n; i++){
            jumps[i]=INT_MAX;
        }
        jumps[0]=0;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]+j>=i){
                    if(jumps[j]+1<jumps[i]){
                        jumps[i]=jumps[j]+1;
                    }
                }
                
            }
        }
        
        
        return jumps[n-1];
        
        
    }
};