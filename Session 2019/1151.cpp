// 1151. Minimum Swaps to Group All 1's Together
// Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.



// Example 1:

// Input: [1,0,1,0,1]
// Output: 1
// Explanation:
// There are 3 ways to group all 1's together:
// [1,1,1,0,0] using 1 swap.
// [0,1,1,1,0] using 2 swaps.
// [0,0,1,1,1] using 1 swap.
// The minimum is 1.
// Example 2:

// Input: [0,0,0,1,0]
// Output: 0
// Explanation:
// Since there is only one 1 in the array, no swaps needed.
// Example 3:

// Input: [1,0,1,0,1,0,0,1,1,0,1]
// Output: 3
// Explanation:
// One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].


// Note:

// 1 <= data.length <= 10^5
// 0 <= data[i] <= 1

// Extra TestCases
// 6
// 4
// 0011
// 8
// 00010111
// 5
// 01001
// 9
// 011011011
// 9
// 010111011
// 18
// 100010101011101101

// Sample Output
// 0
// 1
// 1
// 2
// 1
// 3



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

int minSwaps01(string str, int n, int K){
	//idea - min no of 0s in a K-len substring is the answer
	// K = total 1s in the binary string
	// min no of swaps = min no of 0s in a K len substring
	int cnt0 = 0;
	int ans = n+10;// set it to arbitrary MAX

	// Initial K
	for(int i = 0; i < K; i++){
		if(str[i] == '0')
			cnt0++;
	}

	ans = min(ans,cnt0);

	for(int i = K; i < n; i++){
		if(str[i] == '0')
			cnt0++;
		if(str[i-K] == '0')
			cnt0--;

		ans = min(ans,cnt0);
	}

	return ans;
}


signed main() {

	freopen("input.txt", "r", stdin);
	crap;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string str;
		cin>>str;

		int K = count(str.begin(), str.end(), '1');
		cout << minSwaps01(str,n,K) <<endl;
	}



	return 0;
}




