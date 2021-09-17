typedef vector<int> vi;
class Solution {
public:
    vector<int> go(string str){
        vi ans;
        int n = str.size();
        for(int i = 0; i < n; i++){
            char op = str[i];
            if(op == '+' || op == '-' || op == '*'){
                // break there
                vi left = go(str.substr(0,i));
                vi right = go(str.substr(i+1));
                
                for(auto x: left){
                    for(auto y: right){
                        if(op == '+')
                            ans.push_back(x + y);
                        else if(op == '-')
                            ans.push_back(x - y);
                        else if(op == '*')
                            ans.push_back(x * y);
                    }
                }
            }    
        }
        
        if((int)ans.size() == 0)
            return {stoi(str)};                
        return ans;   
    }
    
    vector<int> diffWaysToCompute(string expression) {
        return go(expression);
    }
};