class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, int>> diff;
        
        for(int i = 0; i < (int)costs.size(); i++){
            diff.push_back({costs[i][1] - costs[i][0], i});
        }
        
        sort(diff.begin(), diff.end());
        int n = costs.size();
        
        int cst = 0;
        for(int i = 0; i < n; i++){
            if(i < n/2)
                cst += costs[diff[i].second][1];//B
            else
                cst += costs[diff[i].second][0];//A
        }
        
        return cst;
        
    }
};
