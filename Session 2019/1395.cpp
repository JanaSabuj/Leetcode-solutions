class Solution {
public:
	int solve(const vector<int>& rating, int k) {
		int size = rating.size();

		int inc[size][k];
		int dec[size][k];
		memset(inc, 0, sizeof(inc));
		memset(dec, 0, sizeof(dec));

		int cntInc = 0;
		int cntDec = 0;

		for (int i = size - 1; i >= 0; i--) {
			inc[i][0] = 1;// cnt of inc seq starting at i
			dec[i][0] = 1;

			for (int j = i + 1; j < size; j++) {
				if (rating[i] < rating[j])
					for (int len = k - 2; len >= 0; len--) {
						inc[i][len + 1] += inc[j][len];
					}
				else if (rating[i] > rating[j])
					for (int len = k - 2; len >= 0; len--) {
						dec[i][len + 1] += dec[j][len];
					}
			}
			cntInc += inc[i][k - 1];
			cntDec += dec[i][k - 1];
		}

		return cntInc + cntDec;

	}
	int numTeams(vector<int>& rating) {
		int k = 3;
		return solve(rating, k);
	}
};
