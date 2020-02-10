76. Minimum Window Substring
Hard

3451

247

Add to List

Share
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
Accepted
328,264
Submissions
987,993



/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/
// #TLE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;

bool isGood( map<char, int>& mp,  map<char, int>& tp, const string& t) {
	for (auto ch : t) {
		if(tp[ch] > mp[ch]) // imp condition
			return false;
	}

	return true;
}

string minWindow(string s, string t) {
	int l = 0, r;
	int n = s.length();

	map<char, int> mp;
	map<char, int> tp;

	for (auto x : t)
		tp[x]++;

	int ans = n;
	int ians = 0;
	int jans = 0;
	bool isWindow = false;

	for (r = 0; r < n; r++) {
		if(!tp[s[r]])
			continue;
		mp[s[r]]++;


		while (isGood(mp, tp, t)) {
			if ((r - l + 1 ) <= ans) {
				ans = r - l + 1;
				ians = l;
				jans = r;
			}

			mp[s[l]]--;
			l++;

			isWindow = true;
		}

	}

	return (isWindow) ? s.substr(ians, ans) : "" ;
}

int main() {
	freopen("input.txt", "r", stdin);

	string s = "ADOBECODEBANC";
	string t = "ABC";

	cout << minWindow(s,t) <<endl;


	return 0;
}


