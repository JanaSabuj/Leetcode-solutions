class Solution {
public:
    string convertToBase7(int num) {
        int x = abs(num);
        string ans = "";        
        do{
            int rem = x % 7;
            x /= 7;
            ans += to_string(rem);
        }while(x);
        
        if(num < 0)
            ans += "-";
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};