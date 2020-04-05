class Solution {
	vector<int> parent;

	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
public:
	Solution(): parent(5000000)  {}
	void make_set(int v) {
		parent[v] = v;

	}
	int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {

			parent[b] = a;

		}
	}

	bool isValid(int r, int c, int n , int m) {
		return r >= 0 and r < n and c >= 0 and c < m;
	}

	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		if (n == 0)
			return 0;
		int m = grid[0].size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1') {
					// init
					make_set(i * m + j);
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == '1') {
					for (int d = 0; d < 4; d++) {
						int r = i + dx[d];
						int c = j + dy[d];

						if (isValid(r, c, n, m))
							if (grid[r][c] == '1') {
								union_sets(i * m + j, r * m + c);
							}
					}
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == '1') {
					cout << i * m + j << " " << parent[i * m + j] << endl;
					if (parent[i * m + j] == i * m + j)
						cnt++;
				}
			}
		}

		return cnt;
	}
};
