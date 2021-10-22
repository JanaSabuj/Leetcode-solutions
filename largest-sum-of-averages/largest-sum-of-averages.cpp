class Solution {    
public:
    double go_part(int idx, int n, int k, vector<int>& nums, vector<vector<double>>& cache) {
        if(idx >= n)
            return 0;
        
        if(cache[idx][k] != -1.0)
            return cache[idx][k];
        
        if(k == 0) {
            int sum = 0;
            int cnt = 0;
            
            for(int i = idx; i < n; i++) {
                sum += nums[i];
                cnt++;
            }
            
            double ans = (double)sum/cnt;            
            return ans;
        }
        
      
        
        double mx = 0.0;
        double cum = 0;
        int cnt = 0;
        double avg = 0.0;

        for(int i = idx; i < n; i++) {
            cum += nums[i];
            cnt++;
            avg = (double) cum / cnt;
            mx = max(mx, avg + go_part(i + 1, n, k - 1, nums, cache));
        }                
        
        return cache[idx][k] = mx;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();                
        vector<vector<double>> cache(n, vector<double>(k, -1.0));
        double ans = go_part(0, n, k-1, nums, cache);               
        return ans;
    }    
};