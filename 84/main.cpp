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
};