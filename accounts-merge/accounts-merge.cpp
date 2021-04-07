struct dsu{
    vector<int> parent;
    int find_set(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find_set(parent[x]);
    }
    
    void _init(int n){
        parent.assign(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        dsu G;
        G._init(n);
        
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < (int)accounts[i].size(); j++){
                string email = accounts[i][j];
                if(mp.count(email)){
                    int pe = G.find_set(mp[email]);
                    int pi = G.find_set(i);                    
                    G.parent[pe] = pi;
                }else{
                    mp[email] = i;
                }
            }
        }
        
        unordered_map<int, vector<string>> em;
        for(auto& e: mp){
            string email = e.first;
            int id = e.second;
            int pe = G.find_set(id);                
            em[pe].push_back(email);
        }
        
        vector<vector<string>> ans;
        for(auto& e: em){
            vector<string>& email_list = e.second;
            sort(email_list.begin(), email_list.end());
            email_list.insert(email_list.begin(), accounts[e.first][0]);
            ans.push_back(email_list);
        }
        
        return ans;
        
    }
};