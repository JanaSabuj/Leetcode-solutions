class Solution {
public:

    int digSum(int n){
        int sum=0;
        while(n>0){
            sum += n%10;
            n/=10;
        }

        return sum;
    }
    bool isHappy(int n, map<int,int> &hash) {
        if(n==1)
            return true;
        
        int sum=digSum(n); 
        
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