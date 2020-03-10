/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int set[], int n, int sum){

	bool dp[n + 1][sum + 1];
	// initialise
	for(int i = 0; i < n + 1; i++){
		for(int j = 0; j < sum + 1; j++){
			if(i == 0)
				dp[i][j] = false;
			else if(j == 0)
				dp[i][j] = true;			 
		}
	}
	dp[0][0] = true;

	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < sum + 1; j++){
			if(set[i - 1] <= j)
				dp[i][j] = (dp[i - 1][j - set[i - 1]] || dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][sum];

}

int main() {
	freopen("input.txt", "r", stdin);
	int set[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum))
		cout << "Found a subset with given sum";
	else
		cout << "No subset with given sum";
	return 0;

}


