/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
	int dp[n + 1][sum + 1];
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < sum + 1; j++) {
			if (i == 0)
				dp[i][j] = 0;
			else
				dp[i][j] = 1;
		}
	}
	dp[0][0] = 1;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < sum + 1; j++) {
			if (arr[i - 1] <= j)
				dp[i][j] = dp[i - 1][j - arr[i - 1]] or dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][sum];

}

bool findPartition(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	if (sum & 1)
		return false;
	else
		return isSubsetSum(arr, n, sum / 2);

}

int main() {
	freopen("input.txt", "r", stdin);
	int arr[] = {3, 5, 1, 2, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	if (findPartition(arr, n))
		cout << "Can be divided into two subsets of equal sum";
	else
		cout << "Can not be divided into two subsets of equal sum";
	return 0;
}


