class Solution {
public:
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        // []
        // [] + []
        // [] + ..... + [] 
        
        const int mod = 1e9 + 7;
        
        // kadane for 1 or 2
        int n = arr.size();
        int csum = 0;
        int msum = 0;
        
        for(int i = 0; i < n * min(2, k); i++){
             csum = max(arr[i % n], (csum + arr[i % n]));
             msum = max(msum, csum);
        }
        
        if(k == 1 or k == 2)
            return msum % mod;
        
        // k > 2
        long long total = accumulate(arr.begin(), arr.end(), 0LL);
        if(total < 0)
            total = 0;
        
        
        long long prod = ((k - 2) % mod * total % mod) % mod;
        long long ans = (msum + prod ) % mod;
        return ans;
        
    }
};