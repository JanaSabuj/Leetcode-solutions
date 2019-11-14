class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        
        int n = A.size();
        for(int i = n -3; i>=0; i--){
            if((A[i] + A[i + 1]) > A[i + 2]){
                //valid
                return A[i] + A[i+1] +A[i+2];
            }
        }
        
        return 0;
    }
};