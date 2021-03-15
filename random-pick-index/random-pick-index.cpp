class Solution {
    vector<int> _nums;
public:
    Solution(vector<int>& nums) {
        _nums.swap(nums);
    }
    
    int pick(int target) {
        int nc = 0;
        int ans;
        int n = _nums.size();
        
        for(int i = 0; i < n; i++){
            if(_nums[i] == target){
                if(nc == 0){
                    nc++;
                    ans = i;
                }else{
                    nc++;
                    // choose this idx with prob 1/n
                    if(rand() % nc == 0){
                        ans = i;
                    }
                }
            }
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */