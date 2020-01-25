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

void reverse(vector<int>& vec, int l, int r){
	while(l < r){
		int temp = vec[l];
		vec[l] = vec[r];
		vec[r] = temp;

		l++;
		r--;
	}
}


void merge(vector<int>& vec, int l, int m, int r){
	int i = l;
	int j = m + 1;

	while(i <= m and vec[i] < 0)
		i++;

	while(j <= r and vec[j] < 0)
		j++;

	reverse(vec, i, m);
	reverse(vec, m+1, j - 1);
	reverse(vec, i, j-1);

}


void merge_sort(vector<int>& vec, int l, int r){

	if(l < r){
		int m = l + (r - l)/2;
		merge_sort(vec, l, m);
		merge_sort(vec, m + 1, r);
		merge(vec, l, m,r);
	}
}


void segregate_modified_merge_sort_stable(vector<int>& vec){

	int n = vec.size();

	int l = 0;
	int r = n - 1;
	// aux func to start the merge sort
	merge_sort(vec, l, r);
}


signed main() {

	freopen("input.txt", "r", stdin);
	crap;
 	vector<int> vec = {-12 ,11 ,-13, -5, 6 ,-7 ,5 ,-3, -6};
 	segregate_modified_merge_sort_stable(vec);
 	print1d(vec);
 

	return 0;
}




