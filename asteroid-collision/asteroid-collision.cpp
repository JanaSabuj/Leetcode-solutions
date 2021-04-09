class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> s;
        for(auto x: ast){
            if(x > 0 || s.empty())
                s.push(x);
            else if(x < 0){
                if(s.empty()){
                    s.push(x);
                    continue;
                }
                    
                int tp = s.top();
                if(tp < 0)
                    s.push(x);
                else{
                    while(!s.empty() and s.top() > 0 and s.top() < abs(x))
                        s.pop();
                    
                    if(s.empty() || s.top() < 0)
                        s.push(x);
                    else if(s.top() == abs(x))
                        s.pop();                    
                }
            }
        }
        
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};