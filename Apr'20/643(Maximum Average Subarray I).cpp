class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n);
        for(int i = 0; i < n; i++){
            pref[i] = nums[i] + (i == 0 ? 0 : pref[i-1]);            
        }
        
        double mx = INT_MIN;
        for(int i = 0; i < n; i++){
            int y = i;
            int x = i - k;
            if(x >= -1){
                int sum = pref[y] - (x == -1 ? 0 : pref[x]);
                mx = max(mx, (double)sum / (double) k);
            }                
        }
        
        return mx;
    }
};
