class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rems(60, 0);
        for(auto x: time) {
            rems[x%60]++;
        }
        
        int cnt = 0;
        int i = 1, j = 59;
        while(i < j) {
            // cout << rems[i] << "-" << rems[j] << endl;            
            cnt += rems[i] * rems[j];  
            i++,j--;
        }
        cnt += rems[30] * (rems[30] - 1)/2;
        cnt += rems[0] * (rems[0] - 1)/2;
        return cnt;
    }
};