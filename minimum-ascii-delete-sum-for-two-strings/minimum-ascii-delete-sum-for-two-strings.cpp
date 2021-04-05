class Solution {
    int dp[1001][1001];
public:
    int go(string& s1, string& s2, int i, int j, int n, int m){
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int cost = 0;
        if(i == n and j == m)
            cost = 0;
        else if(i == n)
            cost = go(s1,s2,i,j+1,n,m) + s2[j];
        else if(j == m)
            cost = go(s1,s2,i+1,j,n,m) + s1[i];
        else if(s1[i] == s2[j])
            cost = go(s1, s2, i + 1, j+1, n, m);
        else{
            int f = go(s1,s2,i+1,j,n,m) + s1[i];// delete s1[i]
            int s = go(s1,s2,i,j+1,n,m) + s2[j];
            cost = min(f,s);
        }
        
        return dp[i][j] = cost;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        memset(dp, -1, sizeof(dp));
        return go(s1, s2, 0, 0, n, m);
    }
};