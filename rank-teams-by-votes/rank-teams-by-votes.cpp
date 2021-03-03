class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        if(n == 0)
            return "";
        
        int cands = votes[0].size();
        vector<vector<int>> vec(26, vector<int>(26,0));
        for(auto str: votes){
            for(int i = 0; i < cands; i++){
                vec[i][str[i] - 'A']++;
            }
        }
        
        sort(votes[0].begin(), votes[0].end(), [&vec](const char& a, const char& b) -> bool{
            // check pos 1 -> pos 2 -> ... -> lex
            for(int i = 0; i < 26; i++){
                if(vec[i][a - 'A'] > vec[i][b - 'A']) return true;
                else if(vec[i][a - 'A'] < vec[i][b - 'A']) return false;
            }
            
            return a < b;
        });
        
        
        return votes[0];
    }
};