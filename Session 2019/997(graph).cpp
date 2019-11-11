class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
       vector<int> in(N+1, 0);
       vector<int> out(N+1, 0);
        
        
        for(auto vec : trust){
            in[vec[1]]++;
            out[vec[0]]++;
        }
        
        
        for(int i = 1; i <= N; i++){
            if(in[i] == (N-1) and (out[i]==0))
            {
                return i;        
            }
        }
        
        return -1;
        
    }
};