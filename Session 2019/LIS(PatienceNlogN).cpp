/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;

int LIS(const vector<int>& A) {
	int n = A.size();
	if (n == 0) {
		return 0;
	}

	vector<int> tail(A.size(), 0);
	int sz = 1;
	tail[0] = A[0];

	for(int i = 1; i < n; i++){
		auto it = lower_bound(tail.begin(), tail.begin() + sz, A[i]);
		if(it == tail.begin() + sz)
			tail[sz++] = A[i];
		else
			*it = A[i];
	}

	return sz;
}

int main() {
	freopen("input.txt", "r", stdin);

	vector<int> vec = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
	cout << LIS(vec);

	return 0;
}


