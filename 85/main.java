class Pair {
	public int first;// ht
	public int second;// idx

	public Pair(int a, int b) {
		first = a;
		second = b;
	}
}


class Solution {
	public int largestRectangleArea(int[] heights) {

		Stack<Pair> s = new Stack<Pair>();
		// stack<pair<int, int>> s;

		int n = heights.length;
		// vector<int> left(n), right(n);
		int[] left = new int[n];
		int[] right = new int[n];

		//left - NSL
		for (int i = 0; i < n; i++) {
			if (s.empty())
				left[i] = -1;
			else if (heights[i] > s.peek().first)
				left[i] = s.peek().second;
			else {
				while (!s.empty() && heights[i] <= s.peek().first)
					s.pop();
				if (s.empty())
					left[i] = -1;
				else
					left[i] = s.peek().second;
			}

			s.push(new Pair(heights[i], i));
		}


		while (!s.empty())
			s.pop();

		//right - 1 3 4 2 1 - NSR
		for (int i = n - 1; i >= 0; i--) {
			if (s.empty())
				right[i] = n;
			else if (heights[i] > s.peek().first)
				right[i] = s.peek().second;
			else {
				while (!s.empty() && heights[i] <= s.peek().first)
					s.pop();
				if (s.empty())
					right[i] = n;
				else
					right[i] = s.peek().second;
			}

			s.push(new Pair(heights[i], i));
		}

		int mx = 0;
		for (int i = 0; i < n; i++) {
			mx = Math.max(mx, heights[i] * (right[i] - left[i] - 1));
		}

		return mx;
	}

	public int maximalRectangle(char[][] mat) {
		int n = mat.length;
		if (n == 0)
			return 0;
		int m = mat[0].length;

		// vector<int> curr(m, 0);
		int[] curr = new int[m];

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

			mx = Math.max(mx, largestRectangleArea(curr));
		}

		return mx;
	}
}