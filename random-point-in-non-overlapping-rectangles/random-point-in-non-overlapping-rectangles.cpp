class Solution {
    vector<int> area;
    vector<vector<int>> rects;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for(auto& vec: rects){
            area.push_back((vec[2] - vec[0] + 1) * (vec[3] - vec[1] + 1));
        }
        
        int n = area.size();
        for(int i = 1; i < n; i++){
            area[i] += area[i-1];
        }
    }
    
    vector<int> pick() {
        
        // pick a rect
        int total = area.back();// total cum
        int val = rand() % total + 1;// random cum
        int idx = lower_bound(area.begin(), area.end(), val) - area.begin();
        
        // pick a pt inside that rect
        int x1 = rects[idx][0];
        int x2 = rects[idx][2];
        
        int y1 = rects[idx][1];
        int y2 = rects[idx][3];
        
        int rx = rand() % (x2 - x1 + 1) + x1;
        int ry = rand() % (y2 - y1 + 1) + y1;
        
        return {rx, ry};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
