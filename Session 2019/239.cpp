class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0)
            return {};
        deque<int> dq;
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            //cond 1 - check if out of window size k
            while(!dq.empty() and dq.front() < i - k + 1)
                dq.pop_front();
            //cond 2 - check if useless element less than curr element
            while(!dq.empty() and nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i>= k-1)
                ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};
