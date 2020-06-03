class Solution {
public:
    
    string solve(string str){
        int n = str.size();
        string ans = "";
        
        for(int i = 0; i < n; i++){
            int cnt = 1;
            while(i + 1 < n and str[i] == str[i+1]){
                cnt++;
                i++;
            }            
            ans = ans + to_string(cnt) + str[i];
        }
        
        return ans;
    }
    
    string countAndSay(int n) {
        vector<string> vec(n + 1);
        vec[1] = "1";        
        
        for(int i = 2; i <= n; i++){
            vec[i] = solve(vec[i - 1]);
        }
        
        return vec[n];
    }
};
