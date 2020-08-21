class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // write your code here
        int same = 0;
        int diff = k;
        int res  = same + diff;
        
        for(int i = 1; i < n; i++){
            // int old_diff = diff;
            same = diff * 1;
            diff = res * (k - 1);
            res = same + diff;
        }
        
        return res;
    }
};
// https://www.lintcode.com/problem/paint-fence/description
