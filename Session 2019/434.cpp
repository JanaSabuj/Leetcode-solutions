class Solution {
public:
    int countSegments(string s) {
        
        int n =s.length();
        // cout << n <<endl;
        if(n == 0)
            return 0;
        
        string delim =" ";
        
        int start = 0;
        int end = s.find(delim);
        vector<string> ans;
        while( end != string::npos){
            
            string str = s.substr(start, end-start);
            if(start!=end){
                cout << start <<" " <<end <<endl;
                ans.push_back(str);
            }
            start = end + delim.length();
            end = s.find(delim, start);
             
        }
        
        if(start!= n){
            cout << start <<" " <<end <<endl;
            ans.push_back(s.substr(start));
     }
        
        return ans.size();
    }
};