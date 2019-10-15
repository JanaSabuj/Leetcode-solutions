typedef long long ll;
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==0)
            return true;
        
        ll l=1, r=num;
        while(l<=r){
            ll mid = l + (r - l)/2;// assumed sqrt
            ll tmp = mid*mid;
            
            if(tmp == num)
                return true;
            else if(tmp > num)
                r = mid - 1;
            else
                l = mid + 1;
                
        }
        
        return false;
    }
};