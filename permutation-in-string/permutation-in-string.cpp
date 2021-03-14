class Solution {
public:
    
    bool valid(unordered_map<char,int>& mp){
        for(auto x: mp)
            if(x.second != 0)
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        // s1 <= s2
        int k = s1.size();
        int n = s2.size();
        
        if(n < k)
            return false;
        
        unordered_map<char,int> mp;
        for(auto x: s1)
            mp[x]++;
        
        for(int i = 0; i < k; i++){
            mp[s2[i]]--;
        }
        
        if(valid(mp))
            return true;
        
        for(int i = k; i < n; i++){
            mp[s2[i]]--;
            mp[s2[i - k]]++;
            
            if(valid(mp))
                return true;
        }
        
        return false;
    }
};