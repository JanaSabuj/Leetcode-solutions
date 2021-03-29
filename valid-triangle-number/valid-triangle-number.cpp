class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if(n < 3)
            return 0;
        
        int cnt = 0;
        for(int k = 2; k < n; k++){
            int i = 0, j = k - 1;
            while(i <= j){
                if(nums[i] + nums[j] > nums[k]){
                    cnt += j - i;
                    j--;
                }else
                    i++;
            }
        }
        
        return cnt;
    }
};
