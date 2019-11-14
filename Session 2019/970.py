import math
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        imax = int(math.log(1000000)/math.log(2)) + 1
        jmax = imax
        ans = []
        hash = {}
        for j in range(0,jmax):
            for i in range(0,imax):
                val = (int) (x**i + y**j)
                print(i,j,val)
                if( val <= bound):
                    if(hash.get(val,-1) == -1):
                        ans.append(val)
                        hash[val] = hash.get(val,0) + 1
                else:
                    break
        
        return ans
                    
        
        