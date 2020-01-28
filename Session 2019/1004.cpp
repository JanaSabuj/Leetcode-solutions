1004. Max Consecutive Ones III
Medium

599

12

Add to List

Share
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

 

Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
Example 2:

Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
 

Note:

1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1 



---------------------------------------------
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0;
        int r;
        
        int n = A.size();
        
        int ans = 0;
        
        int cnt = 0;
        for(r = 0; r < n; r++){
            if(A[r] == 0) cnt++;
            
            while(cnt > K){
                if(A[l] == 0) cnt--;
                l++;
            }
            
            ans = max(ans,r-l+1);
        }
        
        return ans;
    }
};