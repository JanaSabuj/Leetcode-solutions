/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>
using namespace std;

void multiply(int A[2][2], int M[2][2]) {
	int a = A[0][0] * M[0][0] + A[0][1] * M[1][0];
	int b = A[0][0] * M[0][1] + A[0][1] * M[1][1];
	int c = A[1][0] * M[0][0] + A[1][1] * M[1][0];
	int d = A[1][0] * M[0][1] + A[1][1] * M[1][1];

	A[0][0] = a;
	A[0][1] = b;
	A[1][0] = c;
	A[1][1] = d;
}

void power(int A[2][2], int n) {

	if (n == 0) { 
		// int X[2][2] = {
		// 	{, 0},
		// 	{0, 1}
		// };

		// A = X;// not reqd because the control never reaches 0
		return ;
	}

	if (n == 1)
		return ;// A^1 = A

	power(A, n / 2);
	multiply(A, A);
	if (n & 1) {
		// odd
		int M[2][2] = {
			{1, 1},
			{1, 0}
		};
		multiply(A, M);
	}


}

int fib(int n) {

	int A[2][2] = {
		{1, 1},
		{1, 0}
	};

	power(A, n - 1);
	return A[0][0];
}

int main() {
	freopen("input.txt", "r", stdin);

	cout << fib(8) << endl;

	return 0;
}


