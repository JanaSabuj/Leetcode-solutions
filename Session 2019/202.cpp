class Solution {
public:

    int digSumSq(int n){
        int sum=0;
        while(n>0){
            int x = n%10;
            sum += x*x;
            n/=10;
        }

        return sum;
    }
    bool isHappy(int n, map<int,int> &hash) {
        if(n==1)
            return true;
        
        int sum=digSumSq(n); 
        
        if(hash[sum])
            return false;
        
        hash[sum]++;
        // cout << sum <<endl;
        
        return isHappy(sum, hash);
    }
    
    bool isHappy(int n){
        map<int,int> hash;
        
        return isHappy(n,hash);
    }
};