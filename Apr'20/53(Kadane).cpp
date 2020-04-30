class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int a = 0;
        
        for(int x: nums){
            a += x;
            ans = max(ans, a);
            a = max(a, 0);
        }
        
        return ans;
    }
};
