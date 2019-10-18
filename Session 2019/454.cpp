class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int> mp;
        for(auto x:A)
            for(auto y:B)
                mp[x+y]++;
        
        int cnt=0;
        for(auto x:C)
            for(auto y:D)
                if(mp[-(x+y)])
                    cnt += mp[-x-y];
        
        return cnt;
    }
};