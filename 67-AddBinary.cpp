 class Solution {
public:
    string addBinary(string a, string b) {
        
        string result="";
        int s=0;
        
        int i=a.size()-1; int j=b.size()-1;
        
        while(i>=0 or j>=0 or s==1){
            
            s+= ((i>=0)? a[i]-'0' : 0);
            s+= ((j>=0)? b[j]-'0' : 0);
            
            result= char(s%2 + '0') +result;
            
            s/=2;
            
            i--; j--;
        }
        return result;
        
    }
};


//////////////////////////

class Solution {
public:
    long long int mySqrt(long long int x) {
        
        
        long long int s=0,e=x;
       long long  int mid,ans;
        
        while(s<=e){
            
            mid= s+ (e-s)/2;
            
            if(mid*mid==x)
                return mid;
            
            if(mid*mid < x){
                ans=mid;
                s=mid+1;
            }
            
            else {
                e=mid-1;
            }
        }
        
        return ans;
        
    }
};