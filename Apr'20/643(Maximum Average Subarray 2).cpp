class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
     
    bool poss(double x, const vector<int>& nums, int n, int k ){
        double pref[n];
        double nix[n];
        
        pref[0] = (double)nums[0] - x;
        nix[0] = min(0, pref[0]);
        
        
        for(int i = 1; i < n; i++){
            pref[i] = (nums[i] - x) + pref[i-1];
            nix[i] = min(nix[i-1], pref[i]);
        }
        
        
        for(int i = k - 1; i < n; i++){
            double A = pref[i];
            double B = ( (i - k) == -1 ? 0 : nix[i-k]);
            
            if(A >= B)
                return true;
        }
        
        return false;
    }
     
    double maxAverage(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        double lo = *min_element(nums.begin(), nums.end());
        double hi = *max_element(nums.begin(), nums.end());
        
        double ans = hi;
        double mid = hi;
        
        while(hi-lo > 1e-6){
              mid = lo + (hi - lo)/2;
            if(poss(mid, nums, n, k)){
                ans = mid;
                lo = mid;
            }else{
                hi = mid;
            }
        }
        
        return mid;
    }
};
