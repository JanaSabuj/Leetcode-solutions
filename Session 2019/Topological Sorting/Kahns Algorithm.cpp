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


void Kahn(vector<vector<int>>& adj, vector<int>& indegree, int n){
	queue<int> q; // 0 indegree queue
	for(int i = 0; i < n; i++)
		if( indegree[i] == 0 )
			q.push(i);

	vector<int> order;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		order.push_back(u);// topo sort

		for(auto v: adj[u]){
			indegree[v]--;
			if(indegree[v] == 0)
				q.push(v);
		}
	}

	if((int)order.size() != n)
		cout << "NOT a DAG. Cycle is present in the graph" <<endl;
	else{
		print1d(order);
	}


}


signed main() {

	freopen("input.txt", "r", stdin);
	crap;
 	
 	int nodes,edges;
 	cin>>nodes>>edges;

 	vector<vector<int>> adj(nodes);
 	vector<int> indegree(nodes);

 	for(int i = 0; i < edges; i++){
 		int a,b;
 		cin>>a>>b;// 0 based

 		adj[a].push_back(b);
 		indegree[b]++;
 	}

 	print2d(adj);

 	Kahn(adj, indegree, nodes);

	return 0;
}
