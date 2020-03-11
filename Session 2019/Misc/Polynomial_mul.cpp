/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int n,m;
	cin>>n>>m;

	int A[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>A[i];
	}

	int B[m];
	for (int i = 0; i < m; ++i)
	{
		/* code */
		cin>>B[i];
	}

	int prod[n + m - 1];
	memset(prod,0,sizeof(prod));
	for (int i = 0; i < n; ++i)
	{
		/* code */
		for(int j=0; j<m; j++){
			prod[i + j] += A[i] * B[j];// i +j - coeff of x
		}
	}

	for(int i = 0; i <= (n + m - 2); i++){
		if(i == 0)
			cout << prod[0];
		else
			cout << " + " << prod[i] << "x^" << i;
	}

	return 0;
}


