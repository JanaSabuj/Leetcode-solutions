 class Solution {
public:
    bool canJump(vector<int>& nums) {
           
        int n=nums.size();
        int jumps[n];
       for(int i=0; i<n; i++){
            jumps[i]=0;
        }
        if(n==1)
        {  
             
            return true;
             
        }
        
        if(n!=1 && nums[0]==0)
            return false;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]+j>=i){
                    jumps[i]=1;
                    break;
                }
            }
            if(jumps[i]==0)
                return false;
        }
        
        for(int i=0; i<n; i++){
            cout<<jumps[i]<<" ";
        }
        if(jumps[n-1])
       return true;
        else
            return false;
        
        
    }
};