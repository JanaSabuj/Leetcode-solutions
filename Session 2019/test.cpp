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

struct comp{
	bool operator()(const int& x, const int& y){
		// y is the new element
		// y
		// x
		return y > x;// MaxHeap
	}
};


signed main() {

	freopen("input.txt", "r", stdin);
	crap;

	std::vector<int> A = {4, 3, 2, 1, 6, 5};
	// partition(A.begin(), A.end(), [](int x) {
	// 	return x % 2 == 0;
	// });

	// print1d(A);

	//  cout << partition_point(A.begin(), A.end(), [](int x) {return x % 2 == 0;}) - A.begin() << endl;
	
	priority_queue<int, vector<int>, comp> pq;
	for(auto x: A)
		pq.push(x);

	while(!pq.empty()){
		cout << pq.top() <<endl;
		pq.pop();
	}

	return 0;
}




