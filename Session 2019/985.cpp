class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int even = 0;
        for(auto x: A)
            if(x%2 == 0)
                even += x;
        
        for(auto x: queries){
            int idx = x[1];
            int val = x[0];
            
            if(A[idx]%2 == 0){
                //even
                if(val%2==0){
                    //to even add even
                    even += val;
                    A[idx]+=val;
                }else{
                    even -= A[idx];
                    A[idx]+=val;
                    
                }
            }else{
                //odd
                if(val%2 != 0){
                    // to odd add odd
                    A[idx] += val;
                    even += A[idx];
                }else
                    A[idx] += val;
                
            }
            
            ans.push_back(even);
        }
        
        return ans;
    }
};