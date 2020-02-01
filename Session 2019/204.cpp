204. Count Primes
Easy

1546

509

Add to List

Share
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Accepted
303,055
Submissions
994,470
------------------------------------------------------------------------

class Solution {
public:
   int countPrimes(int N){
    // all primes less than N
       
    if(N == 0 or N == 1)
           return 0;
    N--;
    vector<int> sieve(N + 1, 1);// all prime
    sieve[0] = 0;
    sieve[1] = 0;
    
    for(int i = 2; i * i <= N; i++){
        if(sieve[i]){
            for(int j = i*i; j <= N; j+=i){
                sieve[j] = 0;// not a prime
            }
        }
    }
    
    int ans = count(sieve.begin(), sieve.end(), 1);
    return ans;
    
}
};