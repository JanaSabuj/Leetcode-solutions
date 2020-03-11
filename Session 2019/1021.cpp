class Solution {
public:
    string removeOuterParentheses(string str) {
        stack<pair<char, int>> s;
        int n = str.size();
        
        string global = "";
        for(int i = 0; i < n; i++){
            if(str[i] == '(')
                s.push({str[i], i});
            else{
                // closing
                pair<char,int> p = s.top();
                s.pop();
                
                if(s.empty()){
                    // one primitive found
                    int l = p.second + 1;
                    int r = i - 1;
                    
                    if(l <= r)
                        global += str.substr(l, r - l + 1);
                    else
                        global += "";
                }
            }
            
        }
        
        return global;
    }
};
