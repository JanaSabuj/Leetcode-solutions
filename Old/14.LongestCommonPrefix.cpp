class Solution {
public:
    
    string LCP(string s1, string s2)
    {
        int n1=s1.length();
        int n2=s2.length();
        
        int x= min(n1,n2);
        string ans;
        
        for(int i=0; i<x; i++)
        {
            if(s1[i]!=s2[i])
                break;
            ans.push_back(s1[i]);
        }
        
        return ans;
        
    }
    
     
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0)
            return {};
        
        
        
       string prefix=strs[0];
        for(int i=1; i<strs.size();i++)
        {
            prefix=LCP(prefix,strs[i] );
        }
        
        if(prefix.length())
            return prefix;
        else
            return{};
        
        
    }
};