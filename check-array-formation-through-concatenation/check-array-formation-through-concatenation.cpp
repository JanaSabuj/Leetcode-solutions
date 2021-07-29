class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            mp[arr[i]] = i + 1;
        }
        
        
        for(auto vec: pieces){
            int x = vec.size();            
            // if(x == 1) continue; // true
            
            for(int i = 0; i < x; i++){
                if(mp.find(vec[i]) == mp.end()) return false;
                
                if(i > 0)
                    if(mp[vec[i - 1]] + 1 != mp[vec[i]]) return false;
            }
        }
        
        return true;
    }
};