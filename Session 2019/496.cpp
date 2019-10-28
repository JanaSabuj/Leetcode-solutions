class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        int m = nums1.size();
        int n = nums2.size();
        
        if(m==0 or n==0)
            return {};
        
        for(int i=0; i < n; i++){
            mp[nums2[i]] = i;
        }
        
        vector<int> req;
        for(auto x: nums1){
            int idx = mp[x];
            bool found = false;
            int val;
            for(int i = idx ; i < n; i++){
                if(nums2[i] > x){
                    found = true;
                    val = nums2[i];
                    break;
                }
            }
            
            if(found)
                req.push_back(val);
            else
                req.push_back(-1);
        }
        
        return req;
    }
};