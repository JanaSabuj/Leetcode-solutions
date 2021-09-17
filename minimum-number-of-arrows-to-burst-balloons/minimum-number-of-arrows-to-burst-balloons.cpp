class Solution {
public:
    static bool cmp(vector<int>& lhs, vector<int>& rhs){
        // sort asc by ending point
        return lhs[1] < rhs[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
        
        int shoot = points[0][1];
        int bullets = 1;
        
        for(int i = 1; i < n; i++){
            if(points[i][0] <= shoot) continue;
            else {
                bullets++;
                shoot = points[i][1];
            }
        }
        
        return bullets;
    }
};