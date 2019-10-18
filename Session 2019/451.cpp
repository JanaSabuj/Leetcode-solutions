class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto x:s)
            mp[x]++;
        
        vector<pair<int,char>> vec;
        
        for(auto x:mp)
            vec.push_back({x.second, x.first});
        
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        
        string ans = "";
        
        for(auto x: vec){
            
            int t = x.first;
            cout << t <<" " << x.second <<endl;
            while(t--)
                ans += x.second;
        }
        
        return ans;
    }
};