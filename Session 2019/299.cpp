class Solution {
public:
    string getHint(string secret, string guess) {
        
        int cnt=0;
        
        int n = secret.length();
        vector<int> posMatch;
        for(int i=0; i<n; i++){
            if(secret[i] == guess[i])
            {
                cnt++;
                posMatch.push_back(secret[i]);
            }
        }
        
        map<int,int> mp;
        map<int,int> np;
        
        for(auto x:secret)
            mp[x]++;
        
        for(auto x:guess)
            np[x]++;
        
        int ans=0;
        for(auto x:mp){
            ans += min(mp[x.first], np[x.first]);// take the min cnt of the two
        }
        
        for(auto x: posMatch)
            ans--;// subtract the position matchings
        
        string req = to_string(cnt) + "A" + to_string(ans) + "B";
        return req;
        
    }
};