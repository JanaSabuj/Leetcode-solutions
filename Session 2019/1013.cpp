class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        for(auto x: A)
            sum += x;
        if(sum % 3 != 0)
            return false;
        
        int par_sum = sum/3;
        
        int par = 0;
        
        int temp = 0;
        for(int i = 0; i < n; i++){
            temp += A[i];
            
            if(temp == par_sum){
                par++;
                temp = 0;
            }
        }
        
        return par >=3 ;
        
    }
};
