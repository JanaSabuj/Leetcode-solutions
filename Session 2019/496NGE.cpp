/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>
#include <stack>
using namespace std;

void NGE(int arr[], int n){
	stack<int> s;

	for (int i = 0; i < n; ++i)
	{
		/* code */
		int x = arr[i];
		if(s.empty()){
			s.push(x);
			continue;
		}

		if(x <= s.top()){
			s.push(x);
			continue;
		}

		while(!s.empty() and x > s.top()){
			int val = s.top();
			s.pop();
			cout << val <<" -> "<<x <<endl; 
		}

		s.push(x);
	}

	while(!s.empty()){
		cout << s.top() <<" -> " << -1 <<endl;
		s.pop();
	}

}


int main() {
	freopen("input.txt", "r", stdin);

	int arr[] = {5,3,2,10,6,8,1,4,12,7,4};
	int n = sizeof(arr)/sizeof(arr[0]);

	NGE(arr, n);

	return 0;
}


