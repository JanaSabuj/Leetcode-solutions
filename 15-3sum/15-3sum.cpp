class Solution {
public:
    vector<pair<int, int>> p2(int l, int r, vector<int>& nums, int sum) {
        vector<pair<int, int>> vec;
        while (l < r) {
            if (nums[l] + nums[r] == sum) {
                vec.push_back({l, r});


                int ll = nums[l];
                while (ll == nums[l] and l < r) l++;

                int rr = nums[r];
                while (rr == nums[r] and l < r) r--;
            }
            else if (nums[l] + nums[r] < sum)
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

        sort(nums.begin(), nums.end());// sorted array
        
        // misc case
        if(nums[n-1] < 0)
            return {};
        vector<vector<int>> triplets;

        for (int i = 0; i < n - 2; i++) {
            
            // misc: 1st element is > 0, then not possible for triplet sum = 0
            if(nums[i] > 0)
                break;
            
            if (i == 0 or nums[i - 1] < nums[i]) {
                // distinct i

                int a = nums[i];
                vector<pair<int, int>> p = p2(i + 1, n - 1, nums, -a);

                int sz = p.size();

                if (sz) {
                    for (auto pp : p) {
                        triplets.push_back({a, nums[pp.first], nums[pp.second]});
                    }
                }
            }

            // while(a == nums[i] and i < n - 2) i++;
        }

        return triplets;
    }
};

// NOT while(l <= r) bcoz l != r
// NOT p2(i+1,n) bcoz right limit should be n-1







