class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, set<int>> mp;
        map<int,int> np;
        for(auto vec : trust){
            mp[vec[1]].insert(vec[0]);
            np[vec[0]]++;
        }
        
        
        
        
        bool found = false;
        int val;
        for(int i =  1; i <= N; i++){
            if(mp[i].size() == (N-1) and (np[i] == 0))
            {
                found = true;
                val = i;
                break;
            }
        }
        
        if(found)
            return val;
        else
            return -1;
    }
};