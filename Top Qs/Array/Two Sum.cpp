class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(mp[target - nums[i]] > 0){
                ans = {mp[target - nums[i]] - 1, i};
                break;
            }else{
                mp[nums[i]] = i + 1;
            }
        }
        
        return ans;
    }
};