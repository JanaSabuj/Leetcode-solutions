class Solution {
public:

	int largestRectangleArea(vector<int>& heights) {
		stack<pair<int, int>> s;


		int n = heights.size();
		vector<int> left(n), right(n);

		//left - NSL
		for (int i = 0; i < n; i++) {
			if (s.empty())
				left[i] = -1;
			else if (heights[i] > s.top().first)
				left[i] = s.top().second;
			else {
				while (!s.empty() and heights[i] <= s.top().first)
					s.pop();
				if (s.empty())
					left[i] = -1;
				else
					left[i] = s.top().second;
			}

			s.push({heights[i], i});
		}


		while (!s.empty())
			s.pop();
		//right - 1 3 4 2 1 - NSR
		for (int i = n - 1; i >= 0; i--) {
			if (s.empty())
				right[i] = n;
			else if (heights[i] > s.top().first)
				right[i] = s.top().second;
			else {
				while (!s.empty() and heights[i] <= s.top().first)
					s.pop();
				if (s.empty())
					right[i] = n;
				else
					right[i] = s.top().second;
			}

			s.push({heights[i], i});
		}

		int mx = 0;
		for (int i = 0; i < n; i++) {
			mx = max(mx, heights[i] * (right[i] - left[i] - 1));
		}

		return mx;
	}

	int maximalRectangle(vector<vector<char>>& mat) {
		int n = mat.size();
		if (n == 0)
			return 0;
		int m = mat[0].size();

		vector<int> curr(m, 0);

		// copy the first row
		for (int j = 0; j < m; ++j) {
			if (mat[0][j] == '0')
				curr[j] = 0;
			else
				curr[j] = 1;
		}

		int mx = largestRectangleArea(curr);

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] == '0')
					curr[j] = 0;
				else
					curr[j] = curr[j] + 1;
			}

			mx = max(mx, largestRectangleArea(curr));
		}

		return mx;
	}
};