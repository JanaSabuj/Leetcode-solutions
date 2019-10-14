class Solution {
public:
    
    int digSum(int n){
        int sum=0;
        while(n>0){
            sum +=n%10;
            n/=10;
        }
        return sum;
    }
    int addDigits(int num) {
        
        if(num>=0 and num<=9)
            return num;
        
        int sum = digSum(num);
        return addDigits(sum);
        
    }
};