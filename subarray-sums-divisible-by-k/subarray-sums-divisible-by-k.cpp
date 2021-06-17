class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int n = A.size();
        
        int pref = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            pref = (pref + A[i]) % k;
            if(pref < 0)
                pref += k;
            cnt += mp[pref];
            mp[pref]++;
        }
        
        return cnt;
    }
};