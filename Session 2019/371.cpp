class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0)
            return a;
        unsigned int carry = a&b;
        return getSum(a^b, carry << 1);
    }
};