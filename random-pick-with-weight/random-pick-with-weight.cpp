class Solution {
    vector<int> cum;
public:
    
    Solution(vector<int>& w) {
        int prev = 0;        
        for(auto x: w){
            cum.push_back(x + prev);
            prev = cum.back();
        }                
    }
    
    int pickIndex() {
        int total = cum.back();
        int val = rand() % total + 1;
        return lower_bound(cum.begin(), cum.end(), val) - cum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */