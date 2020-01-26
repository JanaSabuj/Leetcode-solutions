/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
//
//		  _____       _           _        _
//		 / ____|     | |         (_)      | |
//		| (___   __ _| |__  _   _ _       | | __ _ _ __   __ _
//		 \___ \ / _` | '_ \| | | | |  _   | |/ _` | '_ \ / _` |
//		 ____) | (_| | |_) | |_| | | | |__| | (_| | | | | (_| |
//		|_____/ \__,_|_.__/ \__,_| |  \____/ \__,_|_| |_|\__,_|
//		                        _/ |
//		                       |__/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
#define int long long int
#define double long double
#define PI acos(-1)

void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;}

void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}

void swap(int& x, int& y) {
	int t = x;
	x = y;
	y = t;
}


int partition_a(vector<int>& vec, int l, int r) {

	int pivot = vec[r];
	int pi = l;

	for (int j = l; j < r; j++) {
		if (vec[j] <= pivot) {
			swap(vec[j], vec[pi]);
			pi++;
		}
	}

	swap(vec[pi], vec[r]);

	return pi;
}

int random_partition(vector<int>& vec, int l, int r){
	int pi = l + (rand() % (r - l + 1));
	swap(vec[r], vec[pi]);
	return partition_a(vec, l, r);
}


int kthSmallest(vector<int>& vec, int l, int r, int K) {

	if (K > 0 and K <= (r - l + 1)) {

		int pos = random_partition(vec, l , r);

		if (pos - l == K - 1)
			return vec[pos];
		else if (pos - l > K - 1)
			return kthSmallest(vec, l, pos - 1, K);
		else
			return kthSmallest(vec, pos + 1, r, l + K - pos - 1);
	}

	return INT_MAX;
}


signed main() {

	freopen("input.txt", "r", stdin);
	crap;

	vector<int> vec = {12, 3, 5, 7, 4, 19, 26};
	vector<int> vec1 = {12, 3, 5, 7, 4, 19, 26};
	sort(vec1.begin(), vec1.end());
	print1d(vec1);

	int K = 3;

	int n = vec.size();
	cout << kthSmallest(vec, 0, n - 1, K);


	return 0;
}




