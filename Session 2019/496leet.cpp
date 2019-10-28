class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        int m = nums1.size();
        
        if(n==0 or m==0)
            return {};
        
        map<int,int> mp;
        stack<int> s;
        
        for(int i=0; i < n; i++){
            int x = nums2[i];// current element being processed
            
            if(s.empty()){
                s.push(x);
                continue;
            }
            
            if(x <= s.top()){
                s.push(x);
                continue;
            }
            
            
            while(!s.empty() and x > s.top()){
                mp[s.top()] = x;
                s.pop();
            }   
            
            s.push(x); 
            
        }
        
        while(!s.empty()){
            mp[s.top()] = -1;
            s.pop();
        }
        
        vector<int> req;
        
        for(auto x: nums1){
            req.push_back(mp[x]);
        }
        
        return req;
    }
};