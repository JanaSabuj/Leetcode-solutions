class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();
        if(n == 1)
            return 0;
        // if(nums[0] == 0)
        //     return false;

        int ladder = 0 + nums[0];
        int stairs = nums[0];
        int jump = 1; // from 0 to 1


        for(int i = 1; i < n; i++){
            if(i == n - 1)
                return jump;
            //updt ladder
            if(i + nums[i] > ladder)
                ladder = i + nums[i];

            stairs--;
            if(stairs == 0){
                jump++;
                stairs = ladder - i;
                if(stairs <= 0)
                    return INT_MAX;
            }
        }

        return jump;
    }
};
