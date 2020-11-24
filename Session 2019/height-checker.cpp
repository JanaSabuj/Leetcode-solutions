class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr = heights;
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += heights[i] != arr[i];
        }
        
        return cnt;
    }
};
