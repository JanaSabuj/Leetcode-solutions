class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        for(int i = 1; i <= n; i++)
            arr.push_back(i);
     
        vector<int> fac(n+1);
        fac[0] = 1;
        for(int i = 1; i < n; i++)
            fac[i] = fac[i-1]*i;
        
        k = k - 1;
        
        string ans = "";
        
        for(int i = n; i > 0; i--){
            
            int idx = k/fac[i-1];
            k = k % fac[i-1];
            cout << idx << endl;
            ans = ans + to_string(arr[idx]);
            arr.erase(arr.begin() + idx);            
        }
        
        return ans;
    }
};
