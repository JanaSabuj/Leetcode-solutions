class Solution {
public:

    vector<vector<int>> pascal(int n) {
        int dp[n + 1][n + 1];
        vector<vector<int>> req;// main ans
        for (int i = 0; i <= n; ++i)
        {
            /* code */
            vector<int> tmp;
            for (int k = 0; k <= i; k++) {
                // nCk

                if (k == 0 or k == i)
                    dp[i][k] = 1;
                else
                    dp[i][k] = dp[i - 1][k - 1] + dp[i - 1][k];

                tmp.push_back(dp[i][k]);

            }
            // row complete
            req.push_back(tmp);
        }
        
        return req;

    }


    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return {};

        vector<vector<int>> req = pascal(numRows - 1);
        return req;

    }
};