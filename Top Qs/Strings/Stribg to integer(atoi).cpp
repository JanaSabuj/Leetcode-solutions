class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        int i = 0;
        bool neg = false;
        while(str[i] == ' ')
            i++;
        
        if(str[i] == '-'){
            neg = true;
            i++;
        }
        else if(str[i] == '+'){
            neg = false;
            i++;
        }
        
        if(!isdigit(str[i]))
            return 0;
        
        long long ans = 0;
        while(i < n){
            if(!isdigit(str[i]))
                break;
            ans = ans * 10 + str[i] - '0';
            i++;
          
            ans = (neg ? -ans : ans);
             if(ans < INT_MIN)
                 return INT_MIN;
              if(ans > INT_MAX)
                 return INT_MAX;
            
            ans = abs(ans);
        }
        
         ans = (neg ? -ans : ans);
        
        
        return ans;
        
        
    }
};