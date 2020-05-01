class Solution {
    set<vector<int>> s;
    vector<int> vec;
public:
    
    void helper(int idx, int &n, int &sum, int target, const vector<int>& arr, vector<int>& vec){
        
        if(sum > target)
            return;
        
        if(sum == target){
            s.insert(vec);
            return;
        }
        
        
        if(idx == n)
            return;
                        
        sum += arr[idx];
        vec.push_back(arr[idx]);
        helper(idx + 1, n, sum, target, arr, vec);
        
        sum -= arr[idx];
        vec.pop_back();
        helper(idx + 1, n, sum, target, arr, vec);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        s.clear();
        vec.clear();
        
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        int sum = 0;
        helper(0, n, sum, target, candidates, vec);
        
        vector<vector<int>> ans;
        ans.assign(s.begin(), s.end());
        
        return ans;
    }
};
