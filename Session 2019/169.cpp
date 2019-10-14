class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> hash;
        for(auto x:nums)
            hash[x]++;
        
        int n = nums.size();
        int ans;
        for(auto x:hash){
            if(x.second > n/2){
                ans = x.first;
                break;
            }
                
        }
        
        return ans;
    }
};