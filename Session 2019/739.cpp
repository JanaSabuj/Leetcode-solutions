739. Daily Temperatures
Medium

2050

65

Add to List

Share
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

Accepted
119,854
Submissions
193,558
---------------------------------------------------------
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& arr) {
		int n = arr.size();
		vector<int> ans(n);
		stack<pair<int, int>> s;
		s.push({arr[0], 0});// (val,idx)

		for (int i = 1; i < n; i++) {
			if (s.empty()) {
				s.push({arr[i], i});
				continue;
			}

			while (!s.empty() and s.top().first < arr[i]) {
				ans[s.top().second] = i - s.top().second;
				s.pop();
			}
			s.push({arr[i], i});
		}

		while (!s.empty()) {
			ans[s.top().second] = 0;
			s.pop();
		}

		return ans;
	}
};