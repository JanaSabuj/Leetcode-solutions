class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int n = str.size();
        
        int idx = n - 1;
        
        for(int i = n - 1; i > 0; i--){
            if(str[i - 1] > str[i]){
                str[i - 1]--;
                idx = i - 1;
            }
        }
        
        
        for(int i = idx + 1; i < n; i++){
            str[i] = '9';
        }
        
        return stoi(str);
    }
};