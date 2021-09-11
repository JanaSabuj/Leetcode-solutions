class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
            ans = max(ans, sum);
        }

        int j = k;
        for (int i = n - 1; i >= n - k; i--) {
            sum = (sum - cardPoints[j - 1] + cardPoints[i]);
            j--;
            ans = max(ans, sum);
        }

        return ans;
    }
};