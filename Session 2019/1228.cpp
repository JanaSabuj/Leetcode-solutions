class Solution {
public:
    int missingNumber(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        int total = ( (n+1) * (arr[0] + arr[n-1])) / 2;
        
        int sum=0;
        for(auto x:arr)
            sum += x;
        
        return total - sum;
            
        
        
        
    }
};