class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
       int n = matrix.size();
        if(n == 0)
            return {};
        
        int m = matrix[0].size();
        
        // int arr[n*m];
        vector<int> arr;
        int r=0,c=0;
        
        // cout << matrix[r][c] <<endl;
        for(int i=0; i<n*m; i++){
            
            arr.push_back(matrix[r][c]);
            // cout << matrix[r][c] <<endl;
            if((r+c)%2 == 0){
                //going up
                if(c == m-1) r++;
                else if(r == 0) c++;
                else{
                    r--;
                    c++;
                }
            }else{
                if(r == n-1) c++;
                else if(c == 0) r++;
                else{
                    r++;
                    c--;
                }
            }
        }
        
        return arr;
    }
};