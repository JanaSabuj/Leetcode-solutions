class Solution {
public:
    
    vector<int> fnsl(vector<int>& ht){
        int n = ht.size();
        stack<int> s;
        
        vector<int> nsl(n);
        for(int i = 0; i < n; i++){
            while(!s.empty() and ht[s.top()] >= ht[i])
                s.pop();
            if(s.empty())
                nsl[i] = -1;
            else
                nsl[i] = s.top();
            
            s.push(i);
        }
        
        return nsl;
    }
    
    vector<int> fnsr(vector<int>& ht){
        int n = ht.size();
        stack<int> s;
        
        vector<int> nsr(n);
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() and ht[s.top()] >= ht[i])
                s.pop();
            
            if(s.empty())
                nsr[i] = n;
            else
                nsr[i] = s.top();
            
            s.push(i);
        }
        
        return nsr;
    }
    
    
    
    int largestRectangleArea(vector<int>& ht) {
       vector<int> nsl = fnsl(ht);
       vector<int> nsr = fnsr(ht);
        
        int mx = 0;
        int n = ht.size();
        for(int i = 0; i < n; i++){
            
            mx = max(mx, (nsr[i] - nsl[i] - 1) * ht[i]);
        }
        
        return mx;
    }
};