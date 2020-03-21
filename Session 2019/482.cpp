class Solution {
public:
    string licenseKeyFormatting(string str, int k) {
        string res = "";
        int n = str.size();
        
        for(int i = n - 1; i >= 0; i--){
            if(str[i] != '-'){
                if(res.size() % (k + 1) == k)
                    res += '-';
                res += toupper(str[i]);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
