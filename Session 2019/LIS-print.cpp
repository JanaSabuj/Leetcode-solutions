/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;

void LIS(const vector<int>& A) {
	int n = A.size();
	vector<int> inc(n, 1);
	vector<int> par(n, -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] and inc[j] + 1 > inc[i]) {
				inc[i] = inc[j] + 1;
				par[i] = j;
			}
		}
	}

	// find the max LIS and its index
	int lis = 0;
	int idx = -1;

	for (int i = 0; i < n; i++) {
		if (inc[i] > lis){
			lis = inc[i];
			idx = i;
		}
	}

	vector<int> path;
	while(idx != -1){
		path.push_back(A[idx]);
		idx = par[idx];
	}

	reverse(path.begin(), path.end());
	
	cout <<"LIS is " << lis <<endl;
	cout <<"Path is : " ;
	for(auto& x: path)
		cout << x <<" ";
	cout <<endl;

}

int main() {
	freopen("input.txt", "r", stdin);

	std::vector<int> vec = {1, 3, 5, 2, 4, 7, 8, 9, 6, 3, 1};

	LIS(vec);


	return 0;
}


