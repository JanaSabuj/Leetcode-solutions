/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;

int add(int a){
 	
 	int arr[] = {0,1,10,11}; 
 	return arr[a];
}

void pAUtil(std::vector<int> &v1, std::vector<int> &v2, int n, int m) {
	//n - bigger
	std::vector<int> ans(n);

	int i = n - 1;
	int j = m - 1;
	int k = n - 1;
	int carry = 0;

	while (j >= 0) {

		int sum = v1[i] + v2[j] + carry;
		// int sum = add(v1[i],v2[j]);
		// sum = sum + carry;

		sum = add(sum);

		int val = sum % 10;
		carry = sum / 10;

		ans[k] = val;
		i--;
		j--;
		k--;
	}

	while (i >= 0) {
		int sum = v1[i] + carry;
		sum = add(sum);
		int val = sum % 10;
		carry = sum / 10;

		ans[k] = val;
		i--;
		k--;
	}

	if (carry) {
		// if a new carry, create a new vector to accomodate the 1
		std::vector<int> newAns;
		newAns.push_back(1);
		for (auto x : ans)
			newAns.push_back(x);

		for (auto x : newAns)
			cout << x << " ";

	}
	else
	{
		for (auto x : ans)
			cout << x << " ";
	}


}

void plusArrray(std::vector<int> &v1, std::vector<int> &v2) {

	int n = v1.size();
	int m = v2.size();

	if (n >= m)
		pAUtil(v1, v2, n, m);
	else
		pAUtil(v2, v1, m, n);


}

int main() {
	freopen("input.txt", "r", stdin);

	string a ="11";
	string b ="11";

	std::vector<int> v1;
	std::vector<int> v2;

	for(auto x:a)
		v1.push_back(x-'0');

	for(auto x:b)
		v2.push_back(x-'0');
 	

	plusArrray(v1, v2);


	return 0;
}


