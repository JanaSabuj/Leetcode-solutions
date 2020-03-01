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

// another soln
class Solution {
public:
    static bool comp(const vector<int>& v1, const vector<int>& v2){
        return v1[1] < v2[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n = points.size();
        if(n == 0)
            return 0;
        sort(points.begin(), points.end(), comp);
        
        int i = 0;
        int cnt = 1;
    
        for(int j = 1; j < n; j++){
            if(points[i][1] < points[j][0]){
                // imp. <= will give extra ans bcoz the common edge-point 
                // can burst both the balloons
                //e.g -> 1,6 6,10 requires 1 arrow not 2. 
                i = j;
                cnt++;
            }
        }
        
        return cnt;
    }
};
