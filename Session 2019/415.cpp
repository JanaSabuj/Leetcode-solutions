class Solution {
public:
    
    string addVec(vector<int> &v1, vector<int> &v2, int n, int m){
        vector<int> ans(n);
        
        int i = n-1;
        int j = m-1;
        int k = n-1;
        
        int carry = 0;
        while(j>=0){
            int sum = v1[i] + v2[j] + carry;
            int val = sum%10;
            carry = sum/10;
            
            ans[k] = val;
            i--;
            j--;
            k--;
        }
        
         while(i>=0){
            int sum = v1[i] + carry;
            int val = sum%10;
            carry = sum/10;
            
            ans[k] = val;
            i--;
            k--;
        }
        
        if(carry){
            
            string req="1";
            
            for(auto x:ans){
                req += to_string(x);
            }
            
            return req;
            
            
        }else{
            string req = "";
            
            for(auto x:ans){
                req += to_string(x);
            }
            
            return req;
        }
        
        
        
    }
    
    string addVec(vector<int> &v1, vector<int> &v2){
        int n = v1.size();
        int m = v2.size();
        
        if(n>=m)
            return addVec(v1,v2,n,m);
        else
            return addVec(v2,v1,m,n);
    }
    
    string addStrings(string num1, string num2) {
        vector<int> v1;
        for(auto x:num1)
            v1.push_back(x - '0');
        
        vector<int> v2;
        for(auto x:num2)
            v2.push_back(x - '0');
        
        return addVec(v1, v2);;
        
    }
};