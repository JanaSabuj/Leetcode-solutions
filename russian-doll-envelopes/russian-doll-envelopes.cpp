#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        int n = envelopes.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i){
            // cout << envelopes[i][0] << " " << envelopes[i][1] << endl;
            for (int j = i - 1; j >= 0; --j){
                if(envelopes[j][0] < envelopes[i][0] and envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }   
            }
            cout << dp[i] << " ";
        }

       return *max_element(dp.begin(), dp.end());
    }
};