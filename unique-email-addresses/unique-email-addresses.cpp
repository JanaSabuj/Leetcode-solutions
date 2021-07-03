class Solution {
public:
    string sanitise(string& str){
        stringstream ss;
        ss << str;
        
        string token;
        while(getline(ss, token, '+')){
            break;
        }
        
        string ans = "";
        for(auto x: token)
            if(x != '.')
                ans += x;
        
        return ans;
    }
    int numUniqueEmails(vector<string>& emails) {
        stringstream ss;
        unordered_set<string> st;
        
        for(auto str: emails){
            ss.clear();
            ss << str;
            
            string arr[2];
            string token;
            
            int i = 0;
            while(getline(ss, token, '@')){
                arr[i++] = token;
            }
            
            string local = sanitise(arr[0]);
            string domain = arr[1];
            
            cout << local +  domain << endl;
            st.insert(local + "@" +  domain);
        }
        
        return (int)st.size();
    }
};