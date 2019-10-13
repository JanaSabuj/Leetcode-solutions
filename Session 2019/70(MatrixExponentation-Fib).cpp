/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;
void mult(int A[2][2], int B[2][2]){
	int a = A[0][0]*B[0][0] + A[0][1]*B[1][0];
	int b = A[0][0]*B[0][1] + A[0][1]*B[1][1];
	int c = A[1][0]*B[0][0] + A[1][1]*B[1][0];
	int d = A[1][0]*B[0][1] + A[1][1]*B[1][1];

	A[0][0] = a;
	A[0][1] = b;
	A[1][0] = c;
	A[1][1] = d;
}

void power(int M[2][2], int n){
	if(n==0){
		int X[2][2] = {
			{1,0},
			{0,1}
		};

		M = X;
		return;
	}

	if(n==1)
		return ;

	power(M,n/2);

	mult(M,M);

	if(n&1){
		int A[2][2] = {
			{1,1},
			{1,0}
		};
		mult(M,A);// M at the first because in mult function, the first argument is updated with the product
	}

}


int fib(int n){

	int M[2][2] = {
		{1,1},
		{1,0}
	};

	power(M,n-1);// M^n-1

	return M[0][0];
}

int main() {
	freopen("input.txt", "r", stdin);

	cout << fib(8) <<endl;

	return 0;
}


