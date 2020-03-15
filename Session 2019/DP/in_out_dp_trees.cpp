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

const int N = 100007;
vector<int> adj[N];
int arr[N];
int dp[N];

void dfs(int u, int par){
	dp[u] = arr[u - 1];// dp initial - root

	int mx = 0;
	for(auto child: adj[u]){
		if(child == par) continue;
		dfs(child, u);
		mx = max(mx, dp[child]);
	}

	dp[u] += mx;// dp updt - for rest
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	crap;

	int n;// nodes
	cin >> n;

	// n-1 edges
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}


	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	// dfs called like node, par
	dfs(1, 0);
	cout << dp[1] << endl;
	return 0;
}

----
q:
find max heights if tree is rooted at each node

i/p:
10
1 2
1 3
1 4
2 5
2 6
3 7
4 8
7 9
7 10

o/p: 
3 4 3 4 5 5 4 5 5 5 [Finished in 1.0s]


