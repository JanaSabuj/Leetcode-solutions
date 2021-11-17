class Solution {
public:
    
    bool isPoss(vector<int>& piles, int h, int speed, int n) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            // 3  15
            if(piles[i] <= speed){
                cnt++;
            }else {
                // 17 5
                cnt += piles[i] / speed;
                if(piles[i] % speed != 0)
                    cnt++;
            }
        }
        
        return cnt <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        // k - [3, ,x ,11]
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int low = 1;
        int high = piles[n - 1];
        
        int ans = high;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPoss(piles, h, mid, n)) {
                ans = mid;
                high = mid - 1;
            }else
                low = mid + 1;
        }
        
        return ans;
    }
};