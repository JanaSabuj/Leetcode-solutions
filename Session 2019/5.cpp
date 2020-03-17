class Solution {
public:
	int n;
	int expand(string str, int i, int j) {
		while (i >= 0 and j < n and str[i] == str[j]) {
			i--;
			j++;
		}

		return (j - i- 1);

	}
	string longestPalindrome(string str) {
		n = str.length();

		if (n == 0)
			return "";
		int start = 0;
		int end = 0;

		for (int i = 0; i < n; i++) {
			int len1 = expand(str, i, i);
			int len2 = expand(str, i, i + 1);

			int len = max(len1, len2);
			if (len > end - start + 1) {
				start = i - (len-1)/2;
				end = i + len/2;
			}
		}
        cout << start << " " << end;
		return str.substr(start, end - start + 1);
	}

};
