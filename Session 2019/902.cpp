// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/discuss/168439/C%2B%2B-O(logN)-Clear-code-with-explanation

class Solution {
public:
	int atMostNGivenDigitSet(vector<string>& D, int N) {
		string NS = to_string(N);
		int ns = NS.length();

		int digs = D.size();

		int ans = 0;
        
		for (int i = 1; i < ns; i++) {
			// 1 dig, 2 dig till less than 1 digit of N
			ans += pow(digs, i);
		}

		for (int i = 0; i < ns; i++) {
			// for pos i from the left
			// 5 4 2 3
			// _ _ _ _
			bool equalDig = false;

			for (auto x : D) {
				// int x = stoi(y);
				if (x[0] < NS[i])
					ans += pow(digs, ns - i - 1);
				else if(x[0] == NS[i]){
					equalDig = true;// not being counted
                    break;
                }
                // }else
                //     return ans;
			}
			if (!equalDig)
				return ans;
		}

		return ans + 1;

	}
};