class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        vector<int> req;
        int n = nums.size();
        
        for(auto x:nums){
            if(x == 1)
                cnt++;
            else{
                req.push_back(cnt);
                cnt = 0;
            }
        }
        
        req.push_back(cnt);// if seq ends in 1
        
        return *max_element(req.begin(), req.end());
    }
};