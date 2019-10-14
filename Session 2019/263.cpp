class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        
        while(!(n&1)){
            //2- factor
            n/=2;
        }
        
        // n- odd
         
        for(int i=3; i<=sqrt(n); i+=2){
            
            while(n%i==0){
                if(i!=3 and i!=5)
                    return false;
                n/=i;
            }
        }
        
        if(n>1){
            if(n!=2 and n!=3 and n!=5)
                return false;
        }
        
        
        return true;
        
    }
};