class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> s;
        
        for(auto x: str){
            if(s.empty())
                s.push(x);
            else{
                char c = s.top();
                if(c != x)
                    s.push(x);
                else
                    s.pop();
            }
        }
        
        string req = "";
        while(!s.empty()){
            req += s.top();
            s.pop();
        }
        
        reverse(req.begin(), req.end());
        return req;    
    }
};
