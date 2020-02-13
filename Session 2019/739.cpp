class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		vector<int> dp(n);

		for (int i = n - 1; i >= 0; i--) {
			if (i == n - 1)
				dp[i] = 0;
			else {
				bool flag = false;
				for (int j = i + 1; j < n; j++) {
					if (T[j] > T[i]) {
						dp[i] = j - i;
						flag = true;
						break;
					}
				}

				if (!flag)
					dp[i] = 0;
			}
		}

		return dp;
	}
};