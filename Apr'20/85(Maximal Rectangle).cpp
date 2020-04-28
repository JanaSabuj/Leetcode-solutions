class Solution {
public:
    
    int histogram(vector<int>& hist, int n){
        stack<int> s;
        int mx = 0;
        
        int i = 0;
        while(i < n){
            if(s.empty() or hist[s.top()] < hist[i])
                s.push(i++);
            else{
                int tp = s.top(); s.pop();
                int delta = hist[tp] * (s.empty() ? i : i - s.top() - 1);
                mx = max(mx, delta);
            }
        }
        
        while(!s.empty()){
                int tp = s.top(); s.pop();
                int delta = hist[tp] * (s.empty() ? i : i - s.top() - 1);
                mx = max(mx, delta);
            
        }
        
        return mx;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0 or matrix[0].size() == 0)
            return 0;
        int m = matrix[0].size();
        
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        int mx = 0;
        for(int i = 0; i < n; i++){            
            for(int j = 0; j < m; j++){
                if(i == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1 + dp[i-1][j];
            }
        }
        
        for(int i = 0; i < n; i++){
            mx = max(mx, histogram(dp[i], m));
        }
        
        return mx;
    }
};
