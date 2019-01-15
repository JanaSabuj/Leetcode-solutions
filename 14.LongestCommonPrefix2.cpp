 class Solution {
public:
    
    
    int ML(vector<string> strs)
    {
        int n=strs.size();
        int ans= strs[0].length();
        for(int i=1; i<n;i++)
        {
            if(strs[i].length()<ans)
                ans=strs[i].length();
        }
        cerr<<ans;
        return ans;
        
    }
    
    
    
    
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0)
            return {};
        
        
         int minlen= ML(strs);
        string ans;
        
        for(int i=0; i<minlen; i++)
        {
            int current= strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j][i]!=current)
                    return ans;
                 
            }
            
            ans.push_back(current);
            
        }
        
        
        if(ans.length())
            return ans;
        else
            return {};
        
        
    }
};