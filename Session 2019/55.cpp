class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        
        for(int i = n - 1; i >= 0; i--){
			if(i == n-1)
				dp[i] = 0;
			else if(nums[i] == 0)
				dp[i] = INT_MAX;
			else if(nums[i] >= n - 1 - i)
				dp[i] = 1;
			else{
				int val = nums[i];
                int steps = INT_MAX;

                for(int k = 1; k <= val and (i + k) < n ; k++){
                    steps = min(steps, dp[i + k]);
                }

                if(steps!= INT_MAX)
                    dp[i] = 1 + steps;
                else
                    dp[i] = INT_MAX;
			}
		}

        return !(dp[0] == INT_MAX);
    }
};
----------------------------------------------------------------------------------------------
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        if(nums[0] == 0)
            return false;
        
        int ladder = 0 + nums[0];
        int stairs = nums[0];
        int jump = 1; // from 0 to 1
        
        
        for(int i = 1; i < n; i++){
            if(i == n - 1)
                return true;
            //updt ladder
            if(i + nums[i] > ladder)
                ladder = i + nums[i];
            
            stairs--;
            if(stairs == 0){
                jump++;
                stairs = ladder - i;
                if(stairs <= 0)
                    return false;
            }
        }

        return false;
    }
};
