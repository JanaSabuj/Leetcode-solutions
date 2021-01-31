
class Pair {
	int first;
	int second;

	Pair(int a, int b) {
		first = a;
		second = b;
	}
}

class Solution {
	int[][][] dp;

	Solution() {
		dp = new int[605][105][105];
		for (int i = 0; i < 605; i++)
			for (int j = 0; j < 105; j++)
				for (int k = 0; k < 105; k++)
					dp[i][j][k] = -1;
	}

	int f(int idx, Pair[] arr, int m, int n) {
		// base
		if (idx == arr.length)
			return 0;

		// dp check
		if (dp[idx][m][n] != -1)
			return dp[idx][m][n];

		// main
		int cur0 = arr[idx].first;
		int cur1 = arr[idx].second;

		// exclude this idx
		if (m - cur0 < 0 || n - cur1 < 0)
			return f(idx + 1, arr, m, n);

		// satisfy + include/exclude this idx
		int incl = 1 + f(idx + 1, arr, m - cur0, n - cur1);
		int excl = f(idx + 1, arr, m, n);

		return dp[idx][m][n] = Math.max(incl, excl);
	}

	public int findMaxForm(String[] strs, int m, int n) {
		int k = strs.length;
		// vector<pair<int, int>> arr(k);
		Pair[] arr = new Pair[k];

		for (int i = 0; i < k; ++i) {
			int zer = 0, one = 0;
			for (int j = 0; j < strs[i].length(); j++) {
				char c = strs[i].charAt(j);
				if (c == '0')
					zer++;
				else
					one++;
			}
			arr[i] = new Pair(zer, one);
		}

		return f(0, arr, m, n);
	}
}