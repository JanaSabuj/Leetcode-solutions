class Solution {
    map<char,int> mp;
public:
    
     bool greater(string x,string y){
        
        int n = x.length();
        int m = y.length();
         
         
        for(int i = 0; i < min(n,m); i++)
          if(x[i] != y[i])
            if(mp[x[i]] > mp[y[i]]){
                return true;
            }else
                return false;
        
        if(x.length() < y.length())
            return false;
        if(x.length() > y.length() )
            return true;
        
        return false;
    }
    
    
    bool isAlienSorted(vector<string>& words, string order) {
        
        int val = 1;
        for(auto x:order){
            mp[x] = val;
            val++;
        }
        
        
        vector<string> temp;
        for(auto x: words)
            temp.push_back(x);
        
        
        int n = words.size();
        for(int i = 0; i < n - 1; i++){
            if(greater(words[i], words[i+1]))
                return false;
        }
        
        return true;
        
    }
};