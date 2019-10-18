class Solution {
public:
    
    bool static compare(const vector<int> a,const vector<int> b){
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0)
            return 0;
        sort(points.begin(), points.end(), compare);
        
        int tmp = points[0][1];
        
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(tmp < points[i][0] or tmp > points[i][1]){
                tmp = points[i][1];
                cnt++;
            }
        }
        
        return cnt;
    }
};