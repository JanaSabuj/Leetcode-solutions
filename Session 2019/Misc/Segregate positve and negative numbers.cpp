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


void segregate_nonstable(vector<int> vec){
	int idx = 0;// idx just after last neg no
	for (int i = 0; i < (int)vec.size(); ++i)
	{
		if(vec[i] < 0){
		// condn which will be partitioing to the front			
			int temp = vec[idx];
			vec[idx] = vec[i];
			vec[i] = temp;
			idx++;
		}
	}

	print1d(vec);
}

void partition_stable_stl(vector<int> vec){
	stable_partition(vec.begin(), vec.end(), [](int x) {
		return x < 0 ;
	});

	print1d(vec);
}

void segregate_stable(vector<int> vec){
	// O(N ^ 2) algorithm - Modified Insertion Sort
	int j;
	for(int i = 1; i < (int)vec.size(); i++){
		int key = vec[i];
		if(key > 0)
			continue;
		j = i - 1;
		while(j>=0 and vec[j] > 0){
			vec[j + 1] = vec[j];
			j = j - 1;
		}

		vec[j + 1] = key;
	}

	print1d(vec);
}



signed main() {

	freopen("input.txt", "r", stdin);
	crap;
 	
 	vector<int> vec = {12 ,11 ,-13, -5, 6 ,-7 ,5 ,-3, -6};
 	segregate_nonstable(vec);
 	segregate_stable(vec);
 	partition_stable_stl(vec);

	return 0;
}




