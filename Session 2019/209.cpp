209. Minimum Size Subarray Sum
Medium

1669

91

Add to List

Share
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isnt one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
Accepted
223,902
Submissions
612,391

-------------------------------------------------------------------------------
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& arr) {
        int n = arr.size();
        int l = 0, r;
        int sum = 0;
        
        int ans = n;
        bool isGood = false;
        for(r = 0; r < n; r++){
            sum += arr[r];
            
            while(sum >= s){
                isGood = true;
                ans = min(ans, r - l + 1);
                sum -= arr[l];
                l++;                
            }
            
        }
        
        return ((isGood) ? ans : 0 );
    }

};
