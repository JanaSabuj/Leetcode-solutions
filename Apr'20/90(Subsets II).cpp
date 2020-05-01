class Solution {
    set<vector<int>> s;
    vector<int> vec;
public:
    
    void helper(int idx, int n, const vector<int>& nums){
        if(idx == n){
            s.insert(vec);
            return;            
        }
        
        vec.push_back(nums[idx]);
        helper(idx + 1, n, nums);
        vec.pop_back();
        helper(idx + 1, n, nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        s.clear();
        vec.clear();
        vector<vector<int>> global;
        helper(0, n, nums);
        global.assign(s.begin(), s.end());
        return global;
    }
};
