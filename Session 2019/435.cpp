class Solution {
public:
    
    static bool comp(const vector<int>& v1, const vector<int>& v2){
        return v1[1] < v2[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), comp);
        
        int i = 0;
        int cnt = 1;
    
        for(int j = 1; j < n; j++){
            if(intervals[i][1] <= intervals[j][0]){
                // new interval j added as non-overlapping
                i = j;
                cnt++;
            }
        }
        
        return (n - cnt);
    }
};

@tracymcgrady e.g. [ [1,4], [2,3], [3,4] ], the interval with early start might be very long and incompatible with many intervals. But if we choose the interval that ends early, we'll have more space left to accommodate more intervals. Hope it helps.
