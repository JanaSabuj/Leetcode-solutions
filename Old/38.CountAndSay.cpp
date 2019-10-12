class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1) return "1";
        if(n==2) return "11";
        if(n==3) return "21";
        if(n==4) return "1211";
        if(n==5) return "111221";
        
        string str="111221";
        for(int i=6; i<=n; i++){
            
            string dummy;
            int cnt=1;
            int sz=str.length();
            
                for(int j=0;j<sz;j++){
                    if(str[j]!=str[j+1]){
                        dummy+=cnt+'0';
                        dummy+=str[j];
                        cnt=1;
                    }
                    else
                        cnt++;
                    
                }
            str=dummy;
                       
        }
        
        return str;
        
    }
};