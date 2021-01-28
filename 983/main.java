class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int n = 365;

        // vector<int> f(n + 1);
        int[] f = new int[n + 1];
        int k = days.length;
        int last = days[k - 1];

        // set<int> s;
        Set<Integer> s = new HashSet<Integer>();
        for (int x : days)
            s.add(x);

        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (!s.contains(i)) {
                f[i] = f[i - 1];
                continue;
            }

            f[i] = f[i - 1] + costs[0];

            if (i - 7 >= 0)
                f[i] = Math.min(f[i], f[i - 7] + costs[1]);
            else
                f[i] = Math.min(f[i], costs[1]);

            if (i - 30 >= 0)
                f[i] = Math.min(f[i], f[i - 30] + costs[2]);
            else
                f[i] = Math.min(f[i], costs[2]);

            if (i == last)
                break;
        }

        return f[last];
    }
}