class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(auto x: nums){
            if(mp[x])
                return true;
            mp[x]++;
        }
        return false;
    }
};