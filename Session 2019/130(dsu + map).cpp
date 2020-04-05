class Solution {
	vector<int> parent;
	vector<int> size;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
public:
	Solution(): parent(50000), size(50000) {

	}

	void make_set(int v) {
		parent[v] = v;
		size[v] = 1;

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
			if (size[a] < size[b])
				swap(a, b);
			parent[b] = a;
			size[a] += size[b];
		}
	}


	bool isValid(int r, int c, int n , int m) {
		return r >= 0 and r < n and c >= 0 and c < m;
	}

	void solve(vector<vector<char>>& board) {
		int n = board.size();
		if (n == 0)
			return;
		int m = board[0].size();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				// cout << board[i][j] << " ";
				if (board[i][j] == 'O') {
					make_set(i * m + j);
				}
			}
			// cout << endl;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 'O') {

					for (int d = 0; d < 4; d++) {
						int r = i + dx[d];
						int c = j + dy[d];

						if (isValid(r, c, n, m))
							if (board[r][c] == 'O') {
								union_sets(i * m + j, r * m + c);
							}
					}
				}
			}
		}

		map<int, int> mp;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 or i == n - 1 or j == 0 or j == m - 1) {
					if (board[i][j] == 'O')
						mp[find_set(i * m + j)]++;
				}
			}
		}

		for (int i = 1; i < n - 1; ++i) {
			for (int j = 1; j < m - 1; ++j) {
				if (board[i][j] == 'O') {

					if (mp[find_set(i * m + j)] <= 0) {
						// cout << i * m + j << " " << mp[parent[i * m + j]] << endl;
						board[i][j] = 'X';
					}
				}
			}
		}


	}
};
