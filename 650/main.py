class Solution:
    def minSteps(self, n: int) -> int:
        sum = 0
        # prime factorise
        for i in range(2, int(sqrt(n)) + 1):
            while n % i == 0:
                n//= i;
                sum += i

        if n > 1:
            sum += n
        return sum