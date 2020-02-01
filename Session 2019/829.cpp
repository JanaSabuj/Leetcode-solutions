829. Consecutive Numbers Sum
Hard

236

350

Add to List

Share
Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?

Example 1:

Input: 5
Output: 2
Explanation: 5 = 5 = 2 + 3
Example 2:

Input: 9
Output: 3
Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
Example 3:

Input: 15
Output: 4
Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
Note: 1 <= N <= 10 ^ 9.

Accepted
17,452
Submissions
48,533

-------------------------------------------------------
class Solution {
public:
int consecutiveNumbersSum(long long int S) {
    long long int cnt = 0;
    for(long long int n = 1; n <= sqrt(2*S) ; n++){
        if ((2 * S + n*n - n) % (2 * n) == 0 )
            cnt++;
    }
    
    return cnt;
}
};