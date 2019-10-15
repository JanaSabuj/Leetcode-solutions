class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> mp;
        for(auto x:nums1)
            mp[x]++;
        
        map<int,int> np;
        for(auto x:nums2)
            np[x]++;
        
        vector<int> req;
        
        for(auto x: mp){
            int y = min(mp[x.first], np[x.first]);
            while(y--)
                req.push_back(x.first);
        }
        
        return req;
    }
};