class Solution {
public:
    
    vector<int> pascal(int n){
        int dp[n+1][n+1];
        
        vector<int> ans;
        for(int i=0; i<=n; i++){
            
            
            for(int j=0; j<=i; j++){
                if(j==0 or j==i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                
            }
        }
        
        for(int j=0; j<=n; j++)
            ans.push_back(dp[n][j]);
        
        return ans;
        
    }
    
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans = pascal(rowIndex);
        
        return ans;
    }
};