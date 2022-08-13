class Solution {
public:
    vector<pair<int,int>> p2(int l, int r, vector<int>& nums, int sum) {
        vector<pair<int,int>> vec;
        while(l < r) {
            if(nums[l] + nums[r] == sum) {
                 vec.push_back({l, r});
                 int ll = nums[l];
                 int rr = nums[r];
                 while(ll == nums[l] and l < r) l++;
                 while(rr == nums[r] and l < r) r--;
            }
            else if(nums[l] + nums[r] < sum)
                l++;
            else
                r--;
        }

        return vec;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // [- - - - - - - -]
        // a + b + c = 0
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        
        for(int i = 0; i < n - 2; ) {
            int a = nums[i];
            vector<pair<int,int>> p = p2(i+1,n-1,nums,-a);
            
            int sz = p.size();
            
            if(sz) {
                for(auto pp: p) {
                    triplets.push_back({a, nums[pp.first], nums[pp.second]});
                }
            }
            
            while(a == nums[i] and i < n - 2) i++;
        }

        return triplets;
    }
};





