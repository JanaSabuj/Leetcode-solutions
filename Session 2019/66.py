class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num=""
        for x in digits:
            num += str(x)
        
        num = int(num)
        num = num + 1
        num = str(num)
        arr = [x for x in num]
        return arr
        
        