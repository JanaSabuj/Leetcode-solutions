class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int,int> mp;
        
        for(auto x: nums2){
            if(s.empty()){
                s.push(x);
                continue;
            }
            
            while(!s.empty() and s.top() < x){
                int y = s.top();
                s.pop();
                mp[y] = x;// NGE of y is x                
            }
            
            s.push(x);
            
        }
        
        while(!s.empty()){
            int y = s.top();
            s.pop();
            mp[y] = -1;
        }
        
        int m = nums1.size();
        vector<int> vec(m);
        for(int i = 0; i < m; i++)
            vec[i] = mp[nums1[i]];
        
        return vec;
    }
};
