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
    
    void bs(vector<string>& temp){
        int n = temp.size();
        for(int i = 0; i < n-1; i++)
            for(int j = i+1; j < n; j++)
                if(greater(temp[i], temp[j])){
                    string t = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
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
        
        bs(temp);
        
        
        for(auto x: temp)
            cout << x <<" ";
        
        int n = words.size();
        for(int i = 0; i < n; i++){
            if(words[i] != temp[i])
                return false;
        }
        
        return true;
        
    }
};