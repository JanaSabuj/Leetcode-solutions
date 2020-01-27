74. Search a 2D Matrix
Medium

1250

138

Add to List

Share
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
Accepted
279,108
Submissions
780,245


// -----------------------------------------------------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        // visualize the sorted matrix as a sorted 1D array
        int m = mat.size();
        if(m == 0)
            return false;
        
        int n = mat[0].size();
        if(n == 0)
            return false;
        
        // if(m*n == 1){
        //     return (mat[0][0] == target);
        // }
        
        //Binary Search
        int lo = 0, hi = m*n;// exclusive
        while(lo < hi){
        	
            int mid = lo + (hi - lo)/2;
            int val = mat[mid/n][mid%n];// 2D to 1D mapping
             
            if(target < val)
                hi = mid;//exclusive
            else if(target > val)
                lo = mid + 1;
            else
                return true;
            
        }
        
        return false;
        
    }
};