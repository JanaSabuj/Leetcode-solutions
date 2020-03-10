/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int dp[102][102];

int knapSack(int wt[], int val[], int n, int W) {
	if (n == 0 or W == 0)
		return 0;
	if (dp[n][W] != -1)
		return dp[n][W];// memoise
	if (wt[n - 1] <= W)
		return dp[n][W] = max(val[n - 1] + knapSack(wt, val, n - 1, W - wt[n - 1]), knapSack(wt, val, n - 1, W));
	else
		return dp[n][W] = knapSack(wt, val, n - 1, W);
}

int main() {
	freopen("input.txt", "r", stdin);
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	memset(dp, -1, sizeof(dp));
	cout << knapSack(wt, val, n, W) << endl;
	return 0;
}


