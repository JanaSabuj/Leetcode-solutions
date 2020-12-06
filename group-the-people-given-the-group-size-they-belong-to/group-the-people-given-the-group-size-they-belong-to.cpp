class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        int n = group.size();
        vector<vector<int>> vec(505);
        
        vector<vector<int>> gs;
        for(int i = 0; i < n; i++){
            vec[group[i]].push_back(i);
            if(vec[group[i]].size() == group[i]){
                gs.push_back(vec[group[i]]);
                vec[group[i]].clear();
            }
        }
        
        
        
//         for(int sz = 1; sz <= n; sz++){
//             if(vec[sz].size()){
//                 int t = vec[sz].size();
//                 vector<int> v;
                
//                 for(int i = 1; i <= t; i++){
//                     v.push_back(vec[sz][i - 1]);
//                     if(i % sz == 0){                                                
//                         gs.push_back(v);
//                         v.clear();
//                     }                    
//                 }
                
//             }
//         }
        
        return gs;
    }
};
