// 905. Sort Array By Parity
// Easy

// 690

// 67

// Add to List

// Share
// Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

// You may return any answer array that satisfies this condition.

 

// Example 1:

// Input: [3,1,2,4]
// Output: [2,4,3,1]
// The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

// Note:

// 1 <= A.length <= 5000
// 0 <= A[i] <= 5000
// Accepted
// 153,513
// Submissions
// 208,922
// -----------------------------------------------

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int idx = 0;
        int n = A.size();
        
        for(int i = 0; i < n; i++){
            if(A[i] % 2 == 0){
                int temp = A[idx];
                A[idx++] = A[i];
                A[i] = temp;
            }
        }
        
        return A;
    }
};


