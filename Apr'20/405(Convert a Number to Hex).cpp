class Solution {
public:
    string toHex(int n) {
        
        string ans = "";       
        if(n == 0)
            return "0";
        
        unsigned int num = n;
        while(num){
            int x = num % 16;
            num >>= 4;
            
            string t = "" ;
            t = t + char(x - 10 + 'a');
            ans += (x <= 9 ? to_string(x) : t);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
