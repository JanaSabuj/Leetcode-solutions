class Solution {
	public int minSteps(int n) {
		int sum = 0;

		for (int i = 2; i * i <= n; i++) {
			while (n % i == 0) {
				n /= i;
				sum += i;
			}
		}

		if (n > 1)
			sum += n;

		return sum;
	}
}