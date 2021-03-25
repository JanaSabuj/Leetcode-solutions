class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        
        for(auto x: nums)
            mp[x]++;
        
        int cnt = 0;
        for(auto val: mp){
            int x = val.first;
             
            
            if(k == 0){
                if(mp[x] >= 2)
                    cnt++;
            }else{
                if(mp.count(x + k))
                    cnt++;
            }
        }
        
        return cnt;

    }
};
