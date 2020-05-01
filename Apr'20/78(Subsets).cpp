class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> s;
        for(int mask = 0; mask < (1 << n); mask++){
            vector<int> t;
            for(int i = 0; i < n; i++)
                if(mask & (1 << i))
                    t.push_back(nums[i]);            
            s.push_back(t);
        }
        
        return s;
        
    }
};
class Solution {
    vector<vector<int>> global;
public:
    
    void helper(const vector<int>& nums, int idx, int n, vector<int>& ans){
        
        if(idx == n){
            global.push_back(ans);
            return;
        }
        
        ans.push_back(nums[idx]);
        helper(nums, idx + 1, n, ans);
        ans.pop_back();        
        helper(nums, idx + 1, n, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        global.clear();
        vector<int> ans;
        
        helper(nums, 0, n, ans);   
        return global;
    }
};
