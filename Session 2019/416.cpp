class Solution {
public:
	bool canPartition(vector<int>& nums) {
		// s = sum/2
		int sum = 0;
		for (auto x : nums)
			sum += x;

		if (sum & 1)
			return false;

		 sum = sum / 2;

		int n = nums.size();
		bool dp[n + 1][sum + 1];


		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= sum; j++) {
				if (j == 0)
					dp[i][j] = true;
				else if (i == 0)
					dp[i][j] = false;
				else {
					if (nums[i - 1] <= j)
						dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]];
					else
						dp[i][j] = dp[i - 1][j];
				}

			}
		}

		return dp[n][sum];
	}
};
