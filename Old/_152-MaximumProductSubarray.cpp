 class Solution {
public:
    int maxProduct(vector<int>& arr) {
        
        int maxval=1,minval=1,ans=INT_MIN;
        int sz=arr.size();
        for(int i=0; i<sz; i++){
                
            if(arr[i]>0){
                maxval=maxval*arr[i];
                minval=min(minval*arr[i],1);
            }
            
            else if(arr[i]==0){
                minval=1;
                maxval=0;
            }
            
            else {
                 int temp=maxval;
                maxval=minval*arr[i];
                minval=temp*arr[i];
            }
            
            ans=max(ans,maxval);
            if(maxval<=0)
                maxval=1;
        }
        
        return ans;
        
    }
};