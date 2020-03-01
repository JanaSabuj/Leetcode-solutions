/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}

bool comp(const vector<int>& v1, const vector<int>& v2) {
	return v1[1] < v2[1];// sort by the finishing times
}

void activitySelection(vector<vector<int>>& vec) {
	sort(vec.begin(), vec.end(), comp);
	// print2d(vec);

	int i = 0;// first job
	int cnt = 1;
	vector<pair<int, int>> ans;
	int n = vec.size();
	ans.push_back({vec[0][0], vec[0][1]});
	for (int j = 1; j < n; j++) {
		if (vec[i][1] <= vec[j][0]) {
			// select this job
			i = j;
			cnt++;
			ans.push_back({vec[i][0], vec[i][1]});
		}
	}

	cout << cnt << endl;
	for (auto p : ans) {
		cout << "(" << p.first << " " << p.second << ")" << " ";
	}

}

int main() {
	freopen("input.txt", "r", stdin);
	vector<vector<int>> vec = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
		{5, 7}, {8, 9}
	};

	activitySelection(vec);


	return 0;
}


