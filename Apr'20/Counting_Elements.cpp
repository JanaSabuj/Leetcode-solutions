class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int,int> mp;
        
        for(auto x: arr)
            mp[x]++;
        
        int cnt = 0;
        for(auto x: arr)
            if(mp[x+1])
                cnt++;
        return cnt;
    }
};
