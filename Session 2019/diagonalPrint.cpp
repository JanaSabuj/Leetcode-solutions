/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int arr[3][3];

	for (int i = 0; i < 3; ++i)
	{
		/* code */

		for (int j = 0; j < 3; j++) {
			arr[i][j] = i + j * (j - i);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	//Diag -1
	int cnt = 0;
	for (int k = 0; k < 3; k++) {
		if (!(cnt & 1)) {
			int i = k, j = 0;
			while (i >= 0) {
				cout << arr[i][j] << " ";
				i--;
				j++;
			}
			cout << endl;

		}else{
			int i = 0, j = k;
			while(j >=0){
				cout << arr[i][j] <<" ";
				i++;
				j--;
			}
			cout <<endl;
		}

		cnt++;
	}

	for (int k = 1; k < 3; k++) {
		if (!(cnt & 1)) {
			int i = 2, j = k;
			while (j <= 2) {
				cout << arr[i][j] << " ";
				i--;
				j++;
			}
			cout << endl;

		}else{
			int j=2,i=k;
			while(i <=2){
				cout << arr[i][j] <<" ";
				i++;
				j--;
			}
			cout <<endl;
		}

		cnt++;
	}

	return 0;
}


