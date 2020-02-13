/*-------------------------------@greenindia-Sabuj-Jana----------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void NGE2(const vector<int>& arr, int n){

	vector<int> ans(n);
	// iterate from right
	stack<int> s;
	for(int i = n - 1; i >= 0; i--){
		while(!s.empty() and arr[i] > s.top())
			s.pop();

		if(s.empty())
			ans[i] = -1;
		else
			ans[i] = s.top();

		s.push(arr[i]);
	}

	for(int i = 0; i < n; i++)
		cout << arr[i] << "-->" << ans[i] << endl;

}

int main() {
	freopen("input.txt", "r", stdin);
 	
 	vector<int> vec = {11, 13, 21, 3};
 	int n = vec.size();

 	NGE2(vec,n);


	return 0;
}


