class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        for(auto x:A)
            ans.push_back(x*x);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};