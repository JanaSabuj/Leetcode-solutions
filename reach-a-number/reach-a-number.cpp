class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        if(target == 0)
            return 0;
        
        int sum = 0;
        int idx = 1;
        
        while(1){
            sum += idx;
            // cout << sum << endl;                    
            if(sum >= target and (sum - target) % 2 == 0)
                return idx;
            idx++;
        }
        
        return -1;
    }
};