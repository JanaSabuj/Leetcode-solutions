class Solution {
    
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> s;
        int ans = -1;
        
        int i = 0;
        int n = arr.size();
        
        int mx = 0;
        while(i < n){
            if(s.empty() or arr[s.top()] < arr[i])
                s.push(i++);
            else{
                int tp = s.top();
                s.pop();
                // ht * (idx of right smallest&nearest - idx of left smallest&nearest - 1);
                int delta = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                mx = max(mx,delta);
            }
        }
        
        while(!s.empty()){
            int tp = s.top();
            s.pop();
            
            int delta = arr[tp] * (s.empty() ? i: i - s.top() - 1);
            mx = max(mx, delta);
        }
        
        return mx;
        
    }
};
     
