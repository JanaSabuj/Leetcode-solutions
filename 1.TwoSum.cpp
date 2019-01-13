class Solution {
public:
  int reverse(int x) {
      int rev=0;
      int sign=1;
      if(x<0)
      {
           sign=-1;
          x=-x;
      }


      while(x>0){

          if(rev*10.0+ x%10 > 2147483648) return 0;
          rev=rev*10.0+ x%10;

          x/=10;
      }
      return sign*rev;
   }

};
