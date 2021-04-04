class Solution {
public:
    bool checkValidString(string str) {
        stack<int> s1,s2;
        int n = str.size();
        
        for(int i = 0; i < n; i++){
            if(str[i] == '(')
                s1.push(i);
            else if(str[i] == '*')
                s2.push(i);
            else if(str[i] == ')'){
                if(s1.empty() and s2.empty())
                    return false;
                if(!s1.empty())
                    s1.pop();
                else
                    s2.pop();
            }
        }
        
        while(!s1.empty()){
            int l_idx = s1.top(); s1.pop();
            if(s2.empty()) return false;
            int r_idx = s2.top(); s2.pop();
            if(r_idx < l_idx) return false;
        }
        
        return true;
    }
};
