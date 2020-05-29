class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int mod = 1e9 + 7;        
        int n = A.size();
        vector<int> g1(n), g2(n);
        
        stack<int> s;// next smaller element
        // increasing stack
        for(int i = 0; i < n; i++){            
            while(!s.empty() and A[s.top()] > A[i]){
                int x = s.top();
                s.pop();
                g1[x] = i;// NSE
            }            
            s.push(i);
        }
        
        while(!s.empty()){
            int x = s.top();
            s.pop();            
            g1[x] = n;
        }
        
        // for(int i = 0; i < n; i++)
        //     cout << i << 
        
        stack<int> r;
        for(int i = n - 1; i >= 0; i--){
            while(!r.empty() and A[r.top()] >= A[i]){
                int x = r.top();
                r.pop();
                g2[x] = i;// PSE
            }            
            r.push(i);
        }
        
        while(!r.empty()){
            int x = r.top();
            r.pop();            
            g2[x] = -1;
        }                
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            int k = ((g1[i] - i) * (i - g2[i]) * A[i]) % mod;
            cout << k << endl;
            ans += k;
            ans = ans % mod;
        }
        
        return ans;
    }
};
