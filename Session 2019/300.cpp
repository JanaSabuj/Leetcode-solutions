class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        	return 0;

        vector<int> tail(nums.size(), 0);

        tail[0] = nums[0];
        int sz = 1;

        for(int i = 1; i < n; i++){
        	auto itr = lower_bound(tail.begin(), tail.begin() + sz, nums[i]);
        	if(itr == tail.begin() + sz)
        		tail[sz++] = nums[i];
        	else
        		*itr = nums[i];
        }

        return sz;

    }
};