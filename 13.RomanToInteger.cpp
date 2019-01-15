class Solution {
public:
   int romanToInt(string str) {
       int len=str.length();
       int val=0;

       for(int i=0; i<len;)
       {
           if(str[i]=='I' && str[i+1]=='V')
               val+=4;
           else if(str[i]=='I' && str[i+1]=='X')
               val+=9;
           else if(str[i]=='X' && str[i+1]=='L')
               val+=40;
           else if(str[i]=='X' && str[i+1]=='C')
               val+=90;
           else if(str[i]=='C' && str[i+1]=='D')
               val+=400;
           else if(str[i]=='C' && str[i+1]=='M')
               val+=900;
           else
           {
               if(str[i]=='I')
                   val+=1;
               else if(str[i]=='V')
                   val+=5;
               else if(str[i]=='X')
                   val+=10;
               else if(str[i]=='L')
                   val+=50;
               else if(str[i]=='C')
                   val+=100;
               else if(str[i]=='D')
                   val+=500;
               else if(str[i]=='M')
                   val+=1000;

               i++;
               continue;

           }


           i+=2;
           continue;


       }


       return val;
   }
};
