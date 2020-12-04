class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());// nlogn
        int n = nums.size();
        int sum = 0;
        for(auto x: nums)
            sum += x;
        
        int suff = 0;
        int rem;
        vector<int> vec;
        for(int i = n - 1; i >= 0; i--){
            suff += nums[i];
            rem = sum - suff;
            vec.push_back(nums[i]);
            if(suff > rem){
                break;
            }
        }
        
        return vec;
    }
};
