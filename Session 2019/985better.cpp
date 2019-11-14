class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int even = 0;
        for(auto x: A)
            if(!(x&1))
                even += x;
        
        vector<int> ans;
        for(auto x: queries){
            int idx = x[1];
            int val = x[0];
            
            if(A[idx]%2 == 0)
                even -= A[idx];
            
            A[idx] += val;
            
            if(A[idx]%2 == 0)
                even += A[idx];
            
            ans.push_back(even);
        }
        
        return ans;
    }
};