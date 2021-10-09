typedef vector<int> vi;
typedef vector<vector<int>> vvi;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vvi dis(n, vi(n, INT_MAX));
        for(int i = 0; i < n; i++){            
            dis[i][i] = 0;            
        }
        
        for(auto& e: edges){
            dis[e[0]][e[1]] = e[2];
            dis[e[1]][e[0]] = e[2];
        }
        
        // FW
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dis[i][k] < INT_MAX and dis[k][j] < INT_MAX)
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        
        // check for threshold b/w pairs
        int ans = -1;
        int mn = INT_MAX;
        
        for(int i = 0; i < n; i++){
            int cnt = 0;
            
            for(int j = 0; j < n; j++){
                if(i != j and dis[i][j] <= distanceThreshold) cnt++;
            }
            
            if(cnt <= mn){
                mn = cnt;
                ans = i;
            }
        }
        
        return ans;
    }
};