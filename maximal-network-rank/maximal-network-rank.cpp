class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);       
        set<pair<int,int>> st;
        
        for(auto v: roads){
            deg[v[0]]++;
            deg[v[1]]++;
            st.insert({v[0], v[1]});
            st.insert({v[1], v[0]});
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(st.count({i,j}) > 0 or st.count({j,i}) > 0)
                    ans = max(ans, deg[i] + deg[j] - 1);
                else
                    ans = max(ans, deg[i] + deg[j]);
            }
        }
        
        return ans;
}
};