using vi = vector<int>; 
using vvi = vector<vector<int>>;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // FLoyd Warshall - dis[i][j]
        vvi dis(n, vi (n, INT_MAX));
        for (int i = 0; i < n; ++i){
            dis[i][i] = 0;
        }
        
        for(auto& edge: edges) {
            dis[edge[0]][edge[1]] = edge[2];
            dis[edge[1]][edge[0]] = edge[2];
        }

        // kij loop
        for(int k = 0; k < n; k++) {
            for (int i = 0; i < n; ++i){
                for(int j = 0; j < n; j++) {
                    if(dis[i][k] < INT_MAX and dis[k][j] < INT_MAX) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }

        // find the city to drop the bomb
        int city = -1;
        int min_cnt = n;
        for (int i = 0; i < n; ++i){

            int cnt = 0;
            for (int j = 0; j < n; ++j){
                if(i != j and dis[i][j] <= distanceThreshold) cnt++;
            }

            if(cnt <= min_cnt) {
                min_cnt = cnt;
                city = i;
            }
        }

        return city;
    }
};