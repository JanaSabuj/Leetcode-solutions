class NumArray {
    vector<int> vec;
public:
    NumArray(vector<int>& nums) {
        for(auto x:nums)
            vec.push_back(x);
    }
    
    int sumRange(int i, int j) {
        
        int n = vec.size();
        int dp[n + 1];
        
        
        
        for(int i=0; i<=n; i++){
            if(i==0) 
                dp[i] = 0;
            else
                dp[i] = dp[i-1] + vec[i - 1];
        }
        
        return dp[j+1] - dp[i];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */