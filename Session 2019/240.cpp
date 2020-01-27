240. Search a 2D Matrix II
Medium

2302

65

Add to List

Share
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

Accepted
254,295
Submissions
601,865

----------------------------------------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        if(m == 0)
            return false;
        int n = mat[0].size();
        if(n == 0)
            return false;
        
        int i = 0, j = n-1;
        int s = target;
        
        while(i < m and j >= 0){
            int last = mat[i][j];
            if(s == last)
                return true;
            else if(s > last)
                i++;
            else
                j--;
        }
        
        return false;
    }
};