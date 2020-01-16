/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>
using namespace std;

#define MOD 1000000007

int catalan(int n){
	int dp[n + 1];
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = 0;
		for(int j = 0; j < i; j++){
			dp[i] += (dp[j] * dp[i - j - 1]) % MOD;
		}
		dp[i] = dp[i] % MOD;
	}

	return dp[n];
}

int main() {
	freopen("input.txt", "r", stdin);
 	int n = 17;
 	cout << catalan(n) <<endl;


	return 0;
}


