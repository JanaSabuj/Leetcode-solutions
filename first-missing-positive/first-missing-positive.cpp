class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // mex - [1, n+1]
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0)
                nums[i] = n + 1;
        }

        for (int i = 0; i < n; ++i) {
            if (abs(nums[i]) > n) continue;
            int ind = abs(nums[i]) % n;
            nums[ind] = -1 * abs(nums[ind]);
        }

        for (int i = 1; i <= n; ++i) {
            if (nums[i%n] > 0)
                return i;
        }

        return n + 1;
    }
};