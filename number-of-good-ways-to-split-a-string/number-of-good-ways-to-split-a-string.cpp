class Solution {
public:
    int numSplits(string str) {
        int n = str.size();
        vector<int> pref(n), suff(n);

        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(str[i]);
            pref[i] = s.size();
        }

        s.clear();
        for (int i = n - 1; i >= 0; i--) {
            s.insert(str[i]);
            suff[i] = s.size();
        }

        int spl = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (pref[i] == suff[i + 1])
                spl++;
        }

        return spl;
    }
};