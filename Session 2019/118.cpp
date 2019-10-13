/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>
using namespace std;

void pascal(int n){
	int dp[n+1][n+1];

	for (int i = 0; i <= n; ++i)
	{
		/* code */

		for(int k=0; k<= i; k++){
			// nCk
			if(k == 0 or k==i)
				dp[i][k] = 1;
			else
				dp[i][k] = dp[i-1][k-1] + dp[i-1][k];
		}
	}
 	
 	for (int i = 0; i <= n; ++i)
 	{
 		/* code */

 		for(int j=0; j<= i; j++){
 			cout << dp[i][j] << " ";
 		}

 		cout <<endl;
 	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int n=6;
	pascal(n);

	return 0;
}


