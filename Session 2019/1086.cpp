// Statement :
// Given a list of scores of different students, return the average score of each student's top five scores in the order of each student's id.

// Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  The average score is calculated using integer division.
// --------------------------------

// IO:
// Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
// Output: [[1,87],[2,88]]
// Explanation:
// The average of the student with id = 1 is 87.
// The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.
// -------------------------------

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

int getAvg( priority_queue<int>& pq){
	int ans = 0;
	int k = 5;
	while(k--){
		ans += pq.top();
		pq.pop();
	}

	return ans/5;
}

void highFive(const vector<vector<int>>& vec) {
	map<int, priority_queue<int>> hash;
	for (auto row : vec) {
		hash[row[0]].push(row[1]);
	}

	vector<vector<int>> ans;
	for(auto kv: hash){
		int avgF = getAvg(kv.second);
		vector<int> t;
		t.push_back(kv.first);
		t.push_back(avgF);
		ans.push_back(t);
	}

	print2d(ans);
}

signed main() {

	freopen("input.txt", "r", stdin);
	crap;

	vector<vector<int>> vec = {
		{1, 91}, {1, 92}, {2, 93}, {2, 97}, {1, 60}, {2, 77}, {1, 65}, {1, 87}, { 1, 100}, {2, 100}, {2, 76}
	};

	highFive(vec);




	return 0;
}




