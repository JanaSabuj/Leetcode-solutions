// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<int,int> mp;
//         for(int i = 0; i < n; i++) {
//             // 2   t = 7
//             // search (7 - 2)
//             if(mp.count(target - nums[i])) {
//                 // found ans
//                 return {i, mp[target - nums[i]]};
//             }

//             mp[nums[i]] = i;
//         }

//         return {};
//     }
// };

// TC: O(N) - one iteration
// SC: O(N) - wc scenario, all elements will be in hashmap

using pii = pair<int,int>;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pii> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }
        sort(vec.begin(), vec.end());
        // (1,4) (2,1) (5,2) (7,3) (9,0)

        int i = 0, j = n - 1;
        while(i < j) {
            if(vec[i].first + vec[j].first == target)
                return {vec[i].second, vec[j].second};
            else if(vec[i].first + vec[j].first < target)
                i++;
            else
                j--;
        }

        return {};
    }
};

// 2P method hint because : a + b = target and array can be SORTED
// TC: O(NlogN) - sorting the array, then iterating
// SC: O(N) - storing N pairs