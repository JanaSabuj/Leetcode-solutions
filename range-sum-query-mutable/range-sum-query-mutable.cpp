class NumArray {
    vector<int> bit;// x+1
    vector<int> nums;//x
    int x;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        bit.assign(n + 1, 0);
        x = n;
        
        for(int i = 0; i < n; i++)
            updateBit(i, nums[i]);
    }
    
    void updateBit(int idx, int val){
        // bit
        ++idx;
        for(; idx <= x; idx += idx & -idx){
            bit[idx] += val;
        }
    }
    
    // user
    void update(int idx, int val) {
        int delta = val - nums[idx];
        nums[idx] = val;        
        updateBit(idx, delta);
    }
    
    // bit
    int sum(int idx){
        int ret = 0;
        for(++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        
        return ret;
    }
    
    // user
    int sumRange(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */