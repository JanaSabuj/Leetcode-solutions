/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>



using namespace std;

void kadane(int arr[], int n){

	int s=0;
	int ans = *max_element(arr,arr+n);// if all are negative but can't be used for indices printing
	// int ans = *min_element(arr,arr+n)-1;

	// int start=0,end=0, temp=0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		s +=arr[i];
		ans = max(ans,s);

		if(s<0){
			s=0;
		}
	}
	
	cout << ans <<endl;
}

int main() {
	freopen("input.txt", "r", stdin);

	int arr[] = {1,6,-15,7,9,-11};
	int n = sizeof(arr)/sizeof(arr[0]);

	kadane(arr,n);



	return 0;
}


