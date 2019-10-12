class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        arr = s.split()
        if len(arr) == 0:
            return 0
        else:
            return len(arr[-1])
        