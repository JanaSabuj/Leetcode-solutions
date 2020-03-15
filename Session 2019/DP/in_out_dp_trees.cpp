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
int in[N];
int out[N];

void dfs1(int u, int par) {
	in[u] = 0;// root ht

	for (auto child : adj[u]) {
		if (child == par) continue;
		dfs1(child, u);
		in[u] = max(in[u], 1 + in[child]);// we get in[child] if we have got it by dfs
	}

	// in[u] = 1 + mx;// formula DONT KEEP IT OUTSIDE
}

void dfs2(int u, int par) {
	int mx1 = -1;
	int mx2 = -1;

	// find mx1 and mx2 of in[siblings]
	for (auto child : adj[u]) {
		if (child == par) continue;

		if (in[child] >= mx1 ) {
			mx2 = mx1;
			mx1 = in[child];
		} else if (in[child] > mx2)
			mx2 = in[child];
	}

	for(auto child: adj[u]){
		if(child == par) continue;
		int use = mx1;
		if(mx1 == in[child])
			use = mx2;

		out[child] = max(2 + use, 1 + out[u]);	
		dfs2(child, u);
	}


}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	crap;

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));// out[root] = 0;
	dfs1(1, 0);
	dfs2(1, 0);

	int dp[n + 1];

	for (int i = 1; i <= n; i++) {
		dp[i] = max(in[i], out[i]);
		cout << dp[i] << " ";
		// cout << in[i] << " " << out[i] << " " << dp[i] << endl ;
	}

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


