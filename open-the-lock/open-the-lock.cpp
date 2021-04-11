class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> dead;
        for(auto x: deadends)
            dead.insert(x);
        
        if(dead.count("0000"))
            return -1;
        
        set<string> vis;
        queue<pair<string,int>> q;
        q.push({"0000", 0});
        vis.insert("0000");
        
        while(!q.empty()){
            string v = q.front().first;
            int cdis = q.front().second;
            q.pop();
            
            if(v == target)
                return cdis;
            
            for(int i = 0; i < 4; i++){
                int val = v[i] - '0';
                
                
                string tv = v;                                
                int tmp = val;
                
                // 2 ways
                tmp = (val + 1) % 10;                
                tv[i] = (tmp + '0');
                                
                if(!vis.count(tv) and !dead.count(tv)){
                    vis.insert(tv);
                    q.push({tv, cdis + 1});
                }
                
                tmp = (val - 1 + 10) % 10;                
                tv[i] = (tmp + '0');
                                
                if(!vis.count(tv) and !dead.count(tv)){
                    vis.insert(tv);
                    q.push({tv, cdis + 1});
                }
            }
        }
        
        return -1;
    }
};