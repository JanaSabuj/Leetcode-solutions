class Solution {
public:

	int fourDivs(int n) {
		set<int> s;
		int sum = 0;
		for (int i = 1; i <= sqrt(n); i++) {
			if (n % i == 0) {
				if (n / i == i) {
					s.insert(i);
					sum += i;
				} else {
					s.insert(i);
					s.insert(n / i);
					sum += i;
					sum += n / i;
				}
				if (s.size() > 4)
					return 0;
			}
		}

		return (s.size() == 4 ? sum : 0);
	}

	int sumFourDivisors(vector<int>& nums) {
		int ans = 0;
		for (auto x : nums) {
			ans += fourDivs(x);
		}

		return ans;
	}
};
