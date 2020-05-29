class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int n = num.length();
        
        for(int i = 0; i < n; i++){            
            // first check the pop condition
            while(!s.empty() and s.top() > num[i] and k > 0){
                s.pop();
                k--;
            }

            if(s.empty() and num[i] == '0'){
                continue;
            }
            
            s.push(num[i]);            
        }
        
        // if k still remains
        while(k > 0 and !s.empty()){
            s.pop();
            k--;
        }
        
        string ans = "";
        while(!s.empty()){
            char x = s.top();
            s.pop();            
            ans = ans + x;
        }
        
        reverse(ans.begin(), ans.end());        
        return ans.size() == 0 ? "0" : ans;
                
    }
};
