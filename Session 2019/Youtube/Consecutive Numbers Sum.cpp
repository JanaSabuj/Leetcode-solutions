#include <bits/stdc++.h>
using namespace std;

int consecutiveNumbersSum(int S) {
    int cnt = 0;
    for(int n = 1; n <= sqrt(2*S) ; n++){
        if ((2 * S + n*n - n) % (2 * n) == 0 )
            cnt++;
    }
    
    return cnt;
}

// To execute C++, please define "int main()"
int main() {
  
    int N = 43156417;
    cout << consecutiveNumbersSum(N) <<endl;
    
  return 0;
}
