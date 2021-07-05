class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> req;
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        if(n == 0)
            return {};
        
        int s = intervals[0][0];
        int e = intervals[0][1];
        req.push_back({s,e});
        
        for(int i = 1; i < n; i++){
            if(req.back()[1] < intervals[i][0]){
                // disjoint
                req.push_back(intervals[i]);
            }else {
                // overlap
                req.back()[1] = max(req.back()[1], intervals[i][1]);
            }
        }
        
        return req;
    }
};
