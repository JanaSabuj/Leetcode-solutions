/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void kruskal(const vector<pair<int,pair<int,int>>>& edges, int n, int e){
	// sort the edges by wt
	sort(edges.begin(), edges.end());

	int mc = 0;
	vector<pair<int,int>> mst;

	for(int i = 0; i < e; i++){
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int wt = edges[i].first;

		if(root(u) != root(v)){
			// if they lie in diff components
			mc += wt;
			mst.push_back({u,v});

			union1(u,v);// merge them
		}
	}

	cout << "Minimun cost of MST: " << mst << endl;
	for(auto x: mst){
		cout << x.first <<" " << x.second <<endl;
	}
}

int main() {
	freopen("kruskal.txt", "r", stdin);
 	
 	int n,e;
 	cin>>n>>e;

 	vector<pair<int,pair<int,int>>> edges;// edge-list
 	for(int i = 0; i < e; i++){
 		int u,v,wt;
 		cin>>u>>v>>wt;
 		edges.push_back({wt, {u,v}});
 	}

 	kruskal(edges,n,e);



	return 0;
}


