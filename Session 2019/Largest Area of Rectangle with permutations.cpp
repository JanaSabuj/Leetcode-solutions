/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 5

int LA(const vector<vector<int>>& mat) {
	vector<vector<int>> dp(R, vector<int>(C,0));

	for (int j = 0; j < C; j++)
		dp[0][j] = mat[0][j];// 1st col is retained

	for (int i = 1; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mat[i][j] == 0)
				dp[i][j] = 0;
			else
				dp[i][j] = dp[i - 1][j] + 1;
		}
	}

	for(int i = 0; i < R; i++)
		sort(dp[i].begin(), dp[i].end(), greater<int>());

	// for(auto row: dp)
	// 	for(auto val: row)
	// 		cout << val <<" ";

	int ans = 0;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			ans = max(ans, dp[i][j]* (j + 1));

	return ans;

}

int main() {
	freopen("input.txt", "r", stdin);
	vector<vector<int>> mat = {
		{ 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 1, 1 },
		{ 1, 1, 0, 1, 0 }
	};


	cout << LA(mat) << endl;


	return 0;
}


