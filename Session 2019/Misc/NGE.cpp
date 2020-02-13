/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void NGE(const vector<int>& arr, int n) {
	stack<int> s;
	if (n == 0) {
		cout << "Arr is empty!!" << endl;
		return;
	}

	s.push(arr[0]);
	for (int i = 1; i < n; i++) {
		if (s.empty()) {
			s.push(arr[i]);
			continue;
		}

		// push
		while(!s.empty() and s.top() < arr[i]){
			cout << s.top() << "-->" << arr[i] << endl;
			s.pop();
		}

		// push the current element
		s.push(arr[i]);
	}

	// remaining stack members have no NGE
	while(!s.empty()){
		cout << s.top() <<"--->" << -1 << endl;
		s.pop();
	}

}

int main() {
	freopen("input.txt", "r", stdin);

	vector<int> vec = {11, 13, 21, 3};
	int n = vec.size();
	NGE(vec, n);


	return 0;
}


