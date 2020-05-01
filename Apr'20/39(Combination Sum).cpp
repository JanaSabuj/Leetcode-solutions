class Solution {
    vector<vector<int>> global;
    vector<int> vec;
public:
    
    void helper(int idx, int n, int& sum, int target, const vector<int>& arr){
        
        if(sum > target)
            return;
        
        if(idx == n)
            return;
        
        if(sum == target){
            global.push_back(vec);
            return;
        }
        
        sum += arr[idx];
        vec.push_back(arr[idx]);
        helper(idx, n, sum, target, arr);
        
        sum -= arr[idx];
        vec.pop_back();
        helper(idx + 1, n, sum, target, arr);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        global.clear();
        vec.clear();
        
        int sum = 0;
        helper(0, n, sum, target, candidates);
        
        return global;
    }
};
