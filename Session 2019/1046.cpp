1046. Last Stone Weight
Easy

340

18

Add to List

Share
We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose the two heaviest rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then thats the value of last stone.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
Accepted
37,242
Submissions
59,461
-------------------------------------------------------------

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(auto x: stones)
            heap.push(x);
        
        while(heap.size() > 1){
            int y = heap.top(); heap.pop();
            int x = heap.top(); heap.pop();
            
            if(x == y)
                continue;
            else
                heap.push(y - x);
        }
        
        if(heap.size() == 1)
            return heap.top();
        else
            return 0;
    }
};