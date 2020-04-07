class Solution {
public:
	bool isOverlap(const vector<int>& x, const vector<int>& y) {
		int a = max(x[0], y[0]);
		int b = min(x[1], y[1]);

		return a <= b;
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		int n = intervals.size();
		if (n == 0)
			return {};
		vector<vector<int>> ans;

		vector<int> t = intervals[0];

		for (int i = 1; i < n; ++i) {
			if (isOverlap(t, intervals[i])) {
				// overlap
				t[0] = min(t[0], intervals[i][0]);
				t[1] = max(t[1], intervals[i][1]);
			} else {
				ans.push_back(t);
				t = intervals[i];
			}
		}
		ans.push_back(t);

		return ans;
	}
};
