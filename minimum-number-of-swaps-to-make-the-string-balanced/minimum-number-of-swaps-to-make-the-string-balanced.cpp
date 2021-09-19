class Solution {
public:
    int minSwaps(string str) {
        int n = str.size();
        int sz = 0;
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            if(str[i] == '[')
                cnt++;
            else {
                if(cnt <= 0)
                    sz++;
                else
                    cnt--;
            }
        }
        
        // cout << sz << endl;
        return (sz + 1)/2;
    }
};