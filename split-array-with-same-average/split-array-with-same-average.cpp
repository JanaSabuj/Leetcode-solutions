class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        // (sk/nk = s/n) => sk = s * nk / n
        int m = n/2;
        
        int tsum = 0;
        for(auto x: nums)
            tsum += x;
        
        bool isPos = false;
        
        for(int i = 1; i <= m; i++){
            if((tsum * i) % n == 0){
                isPos = true;
                break;
            }
        }
        
        if(!isPos)
            return false;
        
        vector<unordered_set<int>> sum(m + 1);
        sum[0].insert(0);
        
        for(auto val: nums){
            // new val to be included in sum
            
            for(int i = m; i > 0; i--){
                for(auto t: sum[i - 1])
                    sum[i].insert(t + val);
            }
        }
        
        for(int i = 1; i <= m; i++){
            if((tsum * i % n == 0) and sum[i].count((tsum * i) / n))
                return true;
        }
        
        return false;
    }
};