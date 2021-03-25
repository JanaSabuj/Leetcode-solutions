class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         int n = nums.size();
         unordered_map<int,int> mp;
         mp[0] = -1;
        
         int pref = 0;
        int mx = 0;
         for(int i = 0; i < n; i++){
             pref += (nums[i] == 0 ? -1 : nums[i]);
             if(mp.find(pref) != mp.end()){
                 mx = max(mx, i - mp[pref]);
             }else{
                 mp[pref] = i;
             }
         }
        
        return mx;
    }
};
