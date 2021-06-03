class Solution {
    const int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int area[n][2];
        
        // ple
        stack<int> s;
        for(int i = 0; i < n; i++){
            
            while(!s.empty() and arr[s.top()] > arr[i]) s.pop();
            if(s.empty())
                area[i][0] = 0;
            else
                area[i][0] = s.top() + 1;
            s.push(i);
        }
                
        // nle
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){            
            
            while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            if(st.empty())
                area[i][1] = n - 1;
            else
                area[i][1] = st.top() - 1;
            st.push(i);
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            int lo = area[i][0], hi = area[i][1];
            // cout << i << " " << lo << " " << hi << endl;
            long prod = ((i - lo + 1) % mod * (hi - i + 1) % mod) % mod;
            prod = (prod % mod * arr[i] % mod) % mod;
            sum = (sum + prod) % mod;
            // sum = (sum + ((arr[i] % mod * ((i - lo + 1) * (hi - i + 1)) % mod)) % mod) % mod;
        }
        
        cout << mod << endl;
        return sum ;
    }
};