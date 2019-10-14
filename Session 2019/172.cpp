class Solution {
public:
    long long int trailingZeroes(int n) {
        
        long long int count=0;
        
        for(long long int i=5; (n/i)>=1; i*=5){
            count += n/i;    
        }
        
        return count;
    }
};