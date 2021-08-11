class Solution {
public:
    int ans;
    void solve(string& str, int idx, set<string>& st, int subcnt){
        // base
        int n = str.size();
        if(idx == n){
           ans = max(ans,subcnt);
        }
        
        // main
        string sub = "";
        for(int i = idx; i < n; i++){
            sub += str[i];
            if(st.find(sub) == st.end()){
                st.insert(sub);
                cout << sub << endl;
                solve(str, i + 1, st, subcnt + 1);
                st.erase(st.find(sub));
            }
        }        
    }
    
    int maxUniqueSplit(string str) {
        set<string> st;
        ans = 0;
        solve(str, 0, st, 0);    
        
        return ans;
    }
};