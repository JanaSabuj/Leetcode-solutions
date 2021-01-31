class Solution {
public:
	int dp[605][105][105];
	int f(int idx, vector<pair<int, int>>& arr, int m, int n) {
		// base
		if (idx == arr.size())
			return 0;

		// dp check
		if (dp[idx][m][n] != -1)
			return dp[idx][m][n];

		// main
		int cur0 = arr[idx].first;
		int cur1 = arr[idx].second;

		// exclude this idx
		if (m - cur0 < 0 or n - cur1 < 0)
			return f(idx + 1, arr, m, n);

		// satisfy + include/exclude this idx
		int incl = 1 + f(idx + 1, arr, m - cur0, n - cur1);
		int excl = f(idx + 1, arr, m, n);

		return dp[idx][m][n] = max(incl, excl);
	}

	int findMaxForm(vector<string>& strs, int m, int n) {
		int k = strs.size();
		vector<pair<int, int>> arr(k);

		for (int i = 0; i < k; ++i) {
			arr[i] = {count(strs[i].begin(), strs[i].end(), '0'), count(strs[i].begin(), strs[i].end(), '1')};
		}

		memset(dp, -1, sizeof(dp));
		return f(0, arr, m, n);
	}
};