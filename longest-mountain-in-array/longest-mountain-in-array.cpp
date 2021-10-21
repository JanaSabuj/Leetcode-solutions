class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3)
            return 0;
        vector<int> lhill(n, 1), rhill(n, 1);
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] < arr[i])
                lhill[i] = lhill[i - 1] + 1;             
        }

        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] > arr[i+1])
                rhill[i] = rhill[i + 1] + 1;
        }

        int mx = 0;
        for (int i = 1; i < n - 1; ++i){
            if(lhill[i] != 1 and rhill[i] != 1)
                mx = max(mx, lhill[i] + rhill[i] - 1);
        }

        return mx;
    }
};