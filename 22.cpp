class Solution {
    vector<string> ans;
public:
    
    void helper(string& str, int idx,  int cnt, int opens, int k){
        if(opens > k or cnt < 0){
            return;
        }
        
        if(idx == k * 2 and cnt == 0){
            ans.push_back(str);
            return;
        }
        
        if(cnt >= 0){
            str.push_back('(');
            helper(str, idx + 1, cnt + 1, opens + 1, k);
            str.pop_back();
            
            if(cnt > 0){
            str.push_back(')');
            helper(str, idx + 1, cnt - 1, opens,  k);
            str.pop_back();            
            }                
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        string str;
        str.push_back('(');
        helper(str,1, 1, 1,n);
        
        return ans;
    }
};
