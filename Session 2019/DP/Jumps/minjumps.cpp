//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
#include <bits/stdc++.h>
using namespace std;

int t[10000007];
bool gflag = false;

int jumps(const vector<int>& arr, int i, int j, int n){
     
    if(i == j){
        gflag = true;
        return 0;
    }
    
    if(t[i] != -1)
        return t[i];
    
    int val = arr[i];
    int steps = INT_MAX;

    for(int k = 0; k < val and i + k + 1 < n; k++){
        if(arr[i + k + 1] == 0 and (i + k + 1)!= n - 1)
            continue;
        else
            steps = min(steps, jumps(arr, i + k + 1, j, n));
    }
    return t[i] = 1 + steps;
}


int main() {
    int test;
    cin>>test;

    while(test--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        
        memset(t, -1, sizeof(t));
        gflag = false;

        int ans = jumps(arr, 0, n - 1, n);
        if(gflag)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
