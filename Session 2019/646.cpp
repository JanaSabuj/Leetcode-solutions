class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> lis(n, 1);
        
        sort(pairs.begin(), pairs.end());
        
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(pairs[j][1] < pairs[i][0]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        
        return *max_element(lis.begin(), lis.end());
    }
};
