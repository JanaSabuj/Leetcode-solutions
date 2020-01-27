378. Kth Smallest Element in a Sorted Matrix
Medium

1722

101

Add to List

Share
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.

Accepted
148,968
Submissions
286,890

------------------------------------------------------
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue< pair<int,pair<int,int>>, vector< pair<int,pair<int,int>> >, greater< pair<int,pair<int,int>>> > heap;
        
        int n = mat.size();
       
        
        set<pair<int,int>> s;
        s.insert({0,0});
        int cnt = 0;
        
        heap.push({mat[0][0], {0,0}});
        
        while(cnt != (k-1)){
            
            int val = heap.top().first;
            int row = heap.top().second.first;
            int col = heap.top().second.second;
            
            heap.pop();
            
            // r,c+1
            if( row < n and col+1 < n and (s.find({row,col+1}) == s.end()) ){
                s.insert({row,col+1});
                heap.push({mat[row][col+1], {row,col+1}});
            }
            // r+1,c
            if( row+1 < n and col < n and (s.find({row+1,col}) == s.end()) ){
                s.insert({row+1,col});
                heap.push({mat[row+1][col], {row+1,col}});
            }
            
            cnt++;// popped 1 element
            
        }
        
        return heap.top().first;
        
        
    }
};