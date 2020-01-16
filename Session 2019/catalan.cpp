/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>

using namespace std;
#define MOD 1000000007

long long int BC(long long int n, long long int k) {
	long long int res = 1;
	// nCk 10C7
	k = min(k, n  - k);// 10C3
	for (long long int i = 0; i < k; i++) {
		// res = res % MOD;
		res *= (n - i);

		res /= (i + 1);

		// cout << res << endl;
	}
	return res ;
}

int catalan(int n) {
	return BC(2 * n, n) / (n + 1) ;
}

signed main() {
	freopen("input.txt", "r", stdin);
	int n = 17;
	cout << catalan(n) << endl;


	return 0;
}


