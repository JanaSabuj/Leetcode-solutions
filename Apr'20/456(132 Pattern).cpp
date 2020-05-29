class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return false;
        
        vector<int> mv(n);
        mv[0] = nums[0];
        
        for(int i = 1; i < n; i++)
            mv[i] = min(nums[i], mv[i - 1]);// prefix minval -> always a decreasing array
        
        stack<int> s;
        
        for(int j = n - 1; j > 0; j--){
            int numi = mv[j];
            if(nums[j] > numi){
                // increasing stack from aerial top view
                while(!s.empty() and s.top() <= numi)
                    s.pop();// never used even for preceding elements
                
                if(!s.empty() and s.top() < nums[j])
                    return true;
                s.push(nums[j]);
            }
        }
        
        return false;
    }
};
