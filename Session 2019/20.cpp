class Solution {
public:
    bool isValid(string str) {
        if(str == "")
            return true;
        
        stack<char> s;
        for(auto x: str){
            if(x == '(' or x== '[' or x=='{')
                s.push(x);
           else{
                if(s.empty()) return false;
               
                char y = s.top();
                s.pop();
                
                if(x == ')' and y != '(')
                    return false;
                if(x == '}' and y != '{')
                    return false;
                if(x == ']' and y != '[')
                    return false;
                
            }
        }
        
        return s.empty();
    }
};
