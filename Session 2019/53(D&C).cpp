/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int maxSumCrossing(int arr[], int p, int q, int r){
	int lans = INT_MIN;
	int rans = INT_MIN;

	int s=0;
	for(int i=q; i>=p; i--){
		s+=arr[i];
		lans = max(lans,s);
	}

	s=0;
	for(int i=q+1; i<=r; i++){
		s +=arr[i];
		rans = max(rans,s);
	}

	return lans+rans;
}

int maxSumSubarray(int arr[], int p, int r){

	if(p==r)
		return arr[p];
	int q = (p+r)/2;
	int L = maxSumSubarray(arr,p,q);
	int R = maxSumSubarray(arr,q+1,r);

	int C = maxSumCrossing(arr,p,q,r);
	return max({L,R,C});
}


int main() {
	freopen("input.txt", "r", stdin);

	int arr[] = {-1,-6,-15,-17,9,-11};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << maxSumSubarray(arr,0,n-1);



	return 0;
}


