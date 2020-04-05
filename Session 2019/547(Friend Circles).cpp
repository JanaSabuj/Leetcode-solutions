class Solution {
	vector<int> parent;
public:
	Solution() : parent(5000) {

	}

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

	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		if (n == 0)
			return 0;

		for (int i = 0; i < n; ++i) {
			make_set(i);
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (M[i][j] == 1) {
					union_sets(i, j);
				}
			}
		}

		int cnt = 0;

		for (int i = 0; i < n; ++i) {
			if (parent[i] == i)
				cnt++;
		}

		return cnt;
	}
};
