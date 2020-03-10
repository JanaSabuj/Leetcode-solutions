/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int knapSack(int wt[], int val[], int n, int W) {
	int dp[n + 1][W + 1];
	// initialise
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < W + 1; j++) {
			if(i == 0 or j == 0)
				dp[i][j] = 0;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < W + 1; j++) {
			if(wt[i - 1] <= j)
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][W];
}

int main() {
	freopen("input.txt", "r", stdin);
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);

	cout << knapSack(wt, val, n, W) << endl;
	return 0;
}


