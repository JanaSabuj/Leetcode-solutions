/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void initialize(int id[], int size[], int n){
	for(int i = 0; i < n; i++){
		id[i] = i;
		size[i] = 1;
	}
}

int root(int x, int id[]){
	while(id[x] != x){
		id[x] = id[id[x]];
		x = id[x];
	}

	return x;// id[x] == x
}

void union1(int u, int v, int id[], int size[]){
	int p = root(u,id);
	int q = root(v,id);

	if(size[p] < size[q]){
		id[p] = id[q];
		size[q] += size[p];
	}else{
		id[q] = id[p];
		size[p] += size[q];
	}
}

void kruskal(vector<pair<int,pair<int,int>>>& edges, int n, int e){
	// sort the edges by wt
	sort(edges.begin(), edges.end());

	//initialize
	int id[n];
	int size[n];
	initialize(id,size,n);

	int mc = 0;
	vector<pair<int,int>> mst;

	for(int i = 0; i < e; i++){
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int wt = edges[i].first;

		if(root(u,id) != root(v,id)){
			// if they lie in diff components
			mc += wt;
			mst.push_back({u,v});

			union1(u,v,id,size);// merge them
		}
	}

	cout << "Minimun cost of MST: " << mc << endl;
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


