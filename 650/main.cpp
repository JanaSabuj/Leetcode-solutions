#define inf (1 << 30)
class Solution {
public:

    set<pair<int, int>> s;
    int f(int i,  int n,  int j) {
        if (i > n)
            return inf;

        if (i == n)
            return 0;

        if (s.find({i, j}) != s.end())
            return inf;// loop state
        else
            s.insert({i, j});

        //op 1 - copy
        int b = 1 + f(i , n, i);

        //op 2 - paste
        int a = 1 + f(i + j, n, j);

        return min(a, b);
    }

    int minSteps(int n) {
        s.clear();
        int cp = 0;
        return f(1, n, cp);
    }
};

----------------------------------------------------------------------------------
class Solution {
public:
    int minSteps(int n) {
        int ans = 0;

        // prime factors sum
        for (int i = 2; i * i <= n; i++) {

            while (n % i == 0) {
                n /= i;
                ans += i;
            }

        }

        if (n > 1)
            ans += n;
        return ans;
    }
};