class Solution {
public:
    int numMatchingSubseq(string str, vector<string>& words) {
        vector<vector<int>> vec(26);
        int n = str.size();
        
        for(int i = 0; i < n; i++){
            vec[str[i] - 'a'].push_back(i);
        }
        
        int cnt = 0;
        
        for(auto w: words){
            int curr_idx = -1;
            bool flag = true;
            
            for(auto c: w){
                int idx = upper_bound(vec[c - 'a'].begin(), vec[c - 'a'].end(), curr_idx) - vec[c - 'a'].begin();
                if(idx >= (int)vec[c - 'a'].size()){
                    flag = false;
                    break;
                }
                curr_idx = vec[c - 'a'][idx];
            }
            
            if(flag)
                cnt++;
        }
        
        return cnt;
    }
};
