class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            // 2   t = 7
            // search (7 - 2)
            if(mp.count(target - nums[i])) {
                // found ans
                return {i, mp[target - nums[i]]};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

// TC: O(N) - one iteration
// SC: O(N) - wc scenario, all elements will be in hashmap