class Solution {
public:
    bool isHappy(int n, map<int,int> &hash) {
        if(n==1)
            return true;
        
        int cp = n;
        int sum=0;
        
        while(n>0){
            int x = n%10;
            sum += x*x;
            
            n/=10;
        }
        
        if(sum==cp or hash[sum])
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