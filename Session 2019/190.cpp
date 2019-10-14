class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans= 0;
        uint32_t cnt=1;
        
        for(int i=31; i>=0; i--){
            if(n&(1<<i))
                ans +=cnt;
            cnt*=2;
        }
        
        return ans;
       
    }
};