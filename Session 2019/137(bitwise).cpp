class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int result = 0;
          
        for(int i=0; i<=31; i++){
            // ith - bit sum will be done for all numbers in array
            int sum=0;
            int y = (1 << i);
            
            for(auto x: nums){
                if(x & y)
                    sum++;
            }
            
            if(sum%3 != 0)
                result |= y;
                       
        }
        
        return result;
    }
};