class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        int absum=0;
        int neg = 0;
        int mn = INT_MAX;
        for(auto x: A){
            absum += abs(x);
            if(x < 0)
                neg++;
            mn = min(mn, abs(x));
        }
        
        int sum=0;
        if(K <= neg){            
            for(int i = 0; i < K; i++)
                sum += abs(A[i]);
            for(int i = K; i < n; i++)
                sum += A[i];            
        }else{
            int e = K - neg;
            sum = absum;
            if(e & 1)
                sum -= 2*mn;                        
        }
        
        return sum;
            
    }
};
