class Solution {
public:
    int getSumSquares(int n) {
        int sum = 0;
        while (n) {
            int dig = n % 10;
            n /= 10;
            sum += dig * dig;
        }
        return sum;
    }
    bool isHappy(int n) {
        map<int, int> mp;
        while (n) {
            int sum = getSumSquares(n);
            if (sum == 1)
                return true;
            if (mp[sum])
                return false;
            mp[sum]++;
            n = sum;
        }
        return false;
    }
};