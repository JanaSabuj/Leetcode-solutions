/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void kadane(const vector<int>& vec, int n) {
	if (n == 0)
		cout << "Invalid" << endl;
	int sum = vec[0];
	int ans = vec[0];

	for (int i = 1; i < n; i++) {
		sum = max(vec[i], sum + vec[i]);// start or extend
		ans = max(ans, sum);// updt ans
	}

	cout << ans << endl;
}

void kadane1(const vector<int>& vec, int n) {
	if (n == 0)
		cout << "Invalid" << endl;
	int meh = 0;// max ending here
	int ans = INT_MIN;

	for (int i = 0; i < n; i++) {
		meh = meh + vec[i];
		if(meh < vec[i])
			meh = vec[i];
		if(ans < meh)
			ans = meh;
	}

	cout << ans << endl;
}

void kadaneRange(const vector<int>& vec, int n) {
	if (n == 0)
		cout << "Invalid" << endl;
	 int ans = INT_MIN;
	 int sum = 0;
	 int start, end;
	 int s = 0;

	 for(int i = 0; i < n; i++){
	 	sum += vec[i];
	 	if(sum > ans){
	 		// better array
	 		ans = sum;
	 		start = s;
	 		end = i;
	 	}

	 	if(sum < 0){
	 		sum = 0;
	 		s = i + 1;
	 	}
	 }

	 cout << sum << " " << start << " " << end << endl;
}



int main() {
	freopen("input.txt", "r", stdin);
	vector<int> vec = { -2, -3, -4, -1, -2, 1, 5, 3};
	int n = vec.size();

	kadane(vec, n);
	kadane1(vec, n);
	kadaneRange(vec, n);


	return 0;
}


