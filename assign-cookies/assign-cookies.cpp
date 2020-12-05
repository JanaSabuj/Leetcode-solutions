class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        int n = s.size();
        
        int cnt = 0;
        multiset<int> st;
        for(auto x: s)
            st.insert(x);
        
        for(auto x: g){             
            if(st.lower_bound(x) == st.end())
                break;
            auto it = st.lower_bound(x);
            st.erase(it);
            cnt++;
        }
        
        return cnt;
    }
};
