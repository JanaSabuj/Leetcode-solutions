class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int md = 0;
        
        int tx = target[0];
        int ty = target[1];
        
        int stt = abs(tx) + abs(ty);
        
        for(auto g: ghosts){
            if((abs(tx - g[0]) + abs(ty - g[1])) <= stt)
                return false;                
        }
        
        return true;
    }
};