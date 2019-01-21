 class Solution {
public:
    int romanToInt(string s) {
        
        std::unordered_map<char,int> jjh({
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000} 
        });
         
        int sz=s.length();
        int ans=0;
        for(int i=0; i<sz; i++){
            
            ans+=jjh[s[i]];
            if(i==0) continue;
            if(jjh[s[i-1]]<jjh[s[i]])
                ans-=2*jjh[s[i-1]];
             
        }
        
        return ans;
         
    }
};