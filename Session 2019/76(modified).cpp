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
// Optimised
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
	int l = 0, r;
	int n = s.length();

	map<char, int> mp;

	for (auto x : t)
		mp[x]++;

	int ans = n;
	int ians = 0;
	bool isWindow = false;
	int counter = t.length();

	for (r = 0; r < n; r++) {
		
		if(mp[s[r]] > 0)// if this char is needed
			counter--;
		mp[s[r]]--;

		while (counter == 0) {
			if ((r - l + 1 ) <= ans) {
				ans = r - l + 1;
				ians = l;
			}

			mp[s[l]]++;
			if(mp[s[l]] > 0)// this is again needed
				counter++;
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


