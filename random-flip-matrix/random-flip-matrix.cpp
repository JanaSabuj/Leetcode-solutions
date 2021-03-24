class Solution {
    int r, c;
    int total;
    unordered_map<int,int> mp;
public:
    Solution(int n_rows, int n_cols) {
        r = n_rows;
        c = n_cols;
        total = r * c;        
    }
    
    vector<int> flip() {
        int idx = rand() % (total--);
        int r_idx = idx;
        if(mp.find(idx) != mp.end())
            r_idx = mp[idx];
        
        // last
        if(mp.find(total) != mp.end())
            mp[idx] = mp[total];
        else
            mp[idx] = total;
        return {r_idx / c, r_idx % c};
    }
    
    void reset() {
        mp.clear();
        total = r * c;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */