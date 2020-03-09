class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int req = 0;
        for(auto str: ops){
            if(str[0] == 'D'){
                s.push(s.top() * 2);
            }
            else if(str[0] == 'C'){
                s.pop();
            }else if(str[0] == '+'){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.push(x);                
                s.push(x + y);                
            }else{
                int val = stoi(str);
                s.push(val);
            }
        }
        
        while(!s.empty())
            req += s.top(), s.pop();
        
        return req;
    }
};
