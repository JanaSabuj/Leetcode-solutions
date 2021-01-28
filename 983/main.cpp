class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = 365;
        vector<int> f(n + 1);
        int k = days.size();
        int last = days[k - 1];

        set<int> s;
        for (auto x : days)
            s.insert(x);

        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (s.find(i) == s.end()) {
                f[i] = f[i - 1];
                continue;
            }

            f[i] = f[i - 1] + costs[0];

            if (i - 7 >= 0)
                f[i] = min(f[i], f[i - 7] + costs[1]);
            else
                f[i] = min(f[i], costs[1]);

            if (i - 30 >= 0)
                f[i] = min(f[i], f[i - 30] + costs[2]);
            else
                f[i] = min(f[i], costs[2]);

            if (i == last)
                break;
        }

        return f[last];
    }
};
