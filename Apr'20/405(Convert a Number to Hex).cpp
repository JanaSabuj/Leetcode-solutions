class Solution {
public:
    string toHex(int n) {
        
        string ans = "";
        
        map<int,string> mp = {
            {10, "a"},
            {11, "b"},
            {12, "c"},
            {13, "d"},
            {14, "e"},
            {15, "f"},            
        };
        
        if(n == 0)
            return "0";
        
        unsigned int num = n;
        while(num){
            int x = num % 16;
            num >>= 4;
            
            ans += (x <= 9 ? to_string(x) : mp[x]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
