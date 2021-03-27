class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return to_string(nums[0]);
        else if(n == 2){
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }else{
            string ans = "";
            ans += to_string(nums[0]);
            for(int i = 1; i < n; i++){
                if(i == 1)
                    ans += ("/(" + to_string(nums[i]));
                else if(i == n-1)
                    ans += ("/" + to_string(nums[i]) + ")");
                else
                    ans += ("/" + to_string(nums[i]));
            }
            return ans;
        }
        
        return "";
    }
};