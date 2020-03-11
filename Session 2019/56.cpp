// 56. Merge Intervals
// Medium

// 3120

// 240

// Add to List

// Share
// Given a collection of intervals, merge all overlapping intervals.

// Example 1:

// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
// -----------------------------------------------------------------

class Solution {
public:
    
    bool isOverlap(const vector<int>& v1, const vector<int>& v2){
        int first = max(v1[0], v2[0]);
        int last = min(v1[1], v2[1]);
        
        return last>=first ;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n <= 0)
            return {};// return empty array always if 0 inputs irrespective of vect of vec return type.
        
        sort(arr.begin(), arr.end());// NlogN

        stack<vector<int>> s;
        s.push(arr[0]);
        
        for(int i = 1; i < n; i++){
            vector<int> t = s.top();
            
            if(isOverlap(t, arr[i])){
                s.pop();
                // X coord is already the smallest.
                t[1] = max(t[1], arr[i][1]);// update Y coord.
                s.push(t);
            }else{
                s.push(arr[i]);
            }
        }
        
        vector<vector<int>> ans;
        while(!s.empty()){
            vector<int> t = s.top();
            s.pop();
            ans.push_back(t);
        }
        
        reverse(ans.begin(), ans.end());// NlogN - reverse due to stack
        
        return ans;
        
        
    }
};

// another soln
class Solution {
public:
    
    bool isOverlap(const vector<int>& x,const vector<int>& y){
        int left = max(x[0], y[0]);
        int right = min(x[1], y[1]);
        
        return right>=left;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         int n = intervals.size();
        if(n == 0)
            return {};
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        
       
        vector<vector<int>> ans;
        for(int i = 1; i < n; i++){
            if(isOverlap(temp, intervals[i])){
                //updt temp
                temp[0] = min(temp[0], intervals[i][0]);
                temp[1] = max(temp[1], intervals[i][1]);
            }else{
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        
        ans.push_back(temp);
        
        return ans;
    }
};
