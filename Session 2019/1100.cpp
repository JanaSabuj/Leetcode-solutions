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

	// initial K
	for(int i = 0; i < K; i++){
		alpha[S[i] - 'a']++;
	}


	if(check(alpha))
		cnt++;

	// Slide
	for(int i = K; i < n; i++){
		alpha[S[i] - 'a']++;
		alpha[S[i-K] - 'a']--;

		if(check(alpha))
			cnt++;
	}

	return cnt;
}

int KLSub2P(string S, int K){
	// 2-pointer + sliding window
	int l = 0;// left pointer
	int r ;// right pointer

	int n = S.length();
	map<int,int> mp;

	int cnt = 0;// ans

	for(r = 0; r < n; r++){
		mp[S[r] - 'a']++;

		while(mp[S[r] - 'a'] > 1){
			mp[S[l] - 'a'] -=1;// move the pointer left forward
			l++;// ...
		}

		if (r - l + 1 == K){
			cnt++;
			mp[S[l] - 'a']--;//move l forward so that length K is preserved in next 
			l++;// move of r 
		}
	}

	return cnt;
}

signed main() {

	freopen("input.txt", "r", stdin);
	crap;

    string S = "havefunonleetcode";
    int K = 5;

    cout << KLSub(S, K) <<endl;
    cout << KLSub2P(S, K) <<endl;

	return 0;
}




