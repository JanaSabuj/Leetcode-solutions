class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for(auto& tup: bookings){
            int a = tup[0] - 1;
            int b = tup[1] - 1;
            int c = tup[2];
            
            ans[a] += c;
            if(b + 1 < n)
                ans[b+1] -= c;
        }
        
        for(int i = 0; i < n; i++){
            if(i == 0) continue;
            ans[i] += ans[i - 1];
        }
        
        return ans;
    }
};