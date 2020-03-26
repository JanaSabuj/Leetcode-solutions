class Solution {
public:
    string countAndSay(int n) {
        vector<string> ans(n + 1);
        
        ans[1] = "1";
        if(n == 1)
            return "1";
   
        for(int i = 2; i <= n; i++){
            string prev = ans[i-1];
            
            int l = 0;
            int r = 0;
            string temp = "";
            int x = prev.size();
            cout << x << endl;
            
            while(r < x){
                if(prev[r] == prev[l])
                    r++;
                else{
                    temp += to_string(r-l);
                    temp += to_string(prev[l] - '0');
                    l = r;
                }
                    
            }
            
            temp += to_string(r-l);
            temp += to_string(prev[l] - '0');
            
            ans[i] = temp;
            
        }
        
        return ans[n];
    }
};