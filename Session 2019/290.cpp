class Solution {
public:
    
    vector<string> splitString(string s, string delim){
      vector<string> ans;
        int start = 0;
    int end = s.find(delim);
    while (end != std::string::npos)
    {
        // std::cout << s.substr(start, end - start) << std::endl;
        ans.push_back(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
    }

    // std::cout << s.substr(start, end);
    ans.push_back(s.substr(start));

  return ans;
}
    
    bool wordPattern(string pattern, string str) {
       
        vector<int> a;
        map<char,int> hash;
        
        int cnt=1;
        for(auto x:pattern){
            if(hash[x])
                a.push_back(hash[x]);
            else{
                // cout << x <<endl;
                hash[x] = cnt++;
                a.push_back(hash[x]);
            }
        }
        
        // for(auto x:a)
        //     cout<<x;
        
         // string s = "dog cat cat dog";
 string delim = " ";

 vector<string> ans = splitString(str,delim);
        
        vector<int> b;
        cnt=1;
        map<string,int> mp;
        
             for(auto x:ans){
            if(mp[x])
                b.push_back(mp[x]);
            else{
                // cout << x <<endl;
                mp[x] = cnt++;
                b.push_back(mp[x]);
            }
        }
        
//         for(auto x:b)
//             cout<<x;
        
        int n = a.size();
        int m = b.size();
        
        if(n!=m)
            return false;
        for(int i=0; i<n; i++){
            if(a[i] != b[i])
                return false;
        }
        
        
        
        return true;
    }
};