1100. Find K-Length Substrings With No Repeated Characters
Given a string S, return the number of substrings of length K with no repeated characters.

 

Example 1:

Input: S = "havefunonleetcode", K = 5
Output: 6
Explanation: 
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.
Example 2:

Input: S = "home", K = 5
Output: 0
Explanation: 
Notice K can be larger than the length of S. In this case is not possible to find any substring.
 

Note:

1 <= S.length <= 10^4
All characters of S are lowercase English letters.
1 <= K <= 10^4


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

bool check(int alpha[]){
	for(int i = 0; i < 26; i++)
		if(alpha[i] > 1)
			return false;
	return true;
}


int KLSub(string S, int K){
	int alpha[26];
	memset(alpha,0,sizeof(alpha));

	int n = S.length();
	if(K > n)
		return 0;

	int cnt = 0;

	for(int i = 0; i < K; i++){
		alpha[S[i] - 'a']++;
	}


	if(check(alpha))
		cnt++;

	for(int i = K; i < n; i++){
		alpha[S[i] - 'a']++;
		alpha[S[i-K] - 'a']--;

		if(check(alpha))
			cnt++;
	}

	return cnt;
}

signed main() {

	freopen("input.txt", "r", stdin);
	crap;

    string S = "havefunonleetcode";
    int K = 5;

    cout << KLSub(S, K) <<endl;

	return 0;
}




