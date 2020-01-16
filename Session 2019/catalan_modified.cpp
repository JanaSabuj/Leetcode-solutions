/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>
using namespace std;
#define int long long int

#define MOD 1000000007
// #define MOD 1e9+7

int BC( int n,  int k){
	 int dp[n + 1][k + 1];
	for( int i = 0; i <= n; i++){
		for( int j = 0; j <= min(i,k) ; j++){
			if(j == 0 or j == i)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i-1][j-1] % MOD + dp[i-1][j] % MOD ) % MOD;

			// cout << dp[i][j]<<" ";
		}
		// cout << endl;
	}

	return dp[n][k] ;
}

int catalan(int n){
	return ( (BC(2*n,n) % MOD) - (BC(2*n,n + 1) % MOD) + MOD) % MOD;
}

signed main() {
	freopen("input.txt", "r", stdin);
 	int n = 100;
 	cout << catalan(n) <<endl;
 	cout << 129644790 % MOD <<endl;

	return 0;
}


