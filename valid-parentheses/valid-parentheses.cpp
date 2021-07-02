class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(auto x: str){
            if(x == '(' or x == '{' or x == '[')
                s.push(x);
            else{
                if(s.empty())
                    return false;
                char ch = s.top();
                s.pop();
                
                if((x == ')' and ch != '(') || (x == '}' and ch != '{') || (x == ']' and ch != '['))
                    return false;
            }
        }
        
        return s.empty();
    }
};