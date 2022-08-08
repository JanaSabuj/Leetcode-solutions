class Solution {
public:
    pair<int,int> checkPal(int i, int j, int n, string& str) {
        while(i >= 0 and j < n and str[i] == str[j]) {
                i--,j++;
            }
            i++,j--;

            return {i,j};
            // sz = max(sz, j - i + 1);
    }

    string longestPalindrome(string str) {
        int n = str.size();
        int centers = 2*n - 1;
        // * * * * * * * 
        // 0   1   2   3
        //     c
        int sz = 0;
        int l = -1, r = -1;
        for(int c = 0; c < n; c++) {
            // int i = c - 1, j = c + 1;
            pair<int,int> p1 = checkPal(c-1,c+1,n, str);
            pair<int, int> p2 = checkPal(c,c+1,n, str);
            if((p1.second - p1.first + 1) >= sz) {
                sz = (p1.second - p1.first + 1);
                l = p1.first;
                r = p1.second;
            }

            if((p2.second - p2.first + 1) >= sz) {
                sz = (p2.second - p2.first + 1);
                l = p2.first;
                r = p2.second;
            }
        }

        return str.substr(l, sz);
    }
};