class Solution {
public:
    int balancedStringSplit(string str) {
        int cnt = 0;
        int ans = 0;
        for(auto x: str){
            if(x == 'R')
                cnt++;
            else
                cnt--;
            
            if(cnt == 0)
                ans++;
        }
        
        return ans;
    }
};
