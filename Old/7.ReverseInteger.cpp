class Solution {
public:
   bool isPalindrome(int x) {

       if(x<0)
           return false;


       //log n time to extract the highest divisor
       int divisor=1;
       int orig=x;
       while(x>0)
       {
           x/=10;
           divisor*=10;
       }

       divisor/=10;

       x=orig;
       while(x>0)
       {
           int lead= x/divisor;
           int trail= x%10;

           if(lead!=trail)
               return false;

           x=(x%divisor)/10;

           divisor/=100;

       }

       return true;


   }
};
