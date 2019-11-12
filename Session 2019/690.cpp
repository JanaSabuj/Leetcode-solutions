/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> emp, int id) {
        
        queue<int> q;
        q.push(id);
        
        map<int,pair<int,vector<int>>> mp;
        int maxEmpId =  -1;
        for(auto x: emp){
            mp[x->id] = {x->importance, x->subordinates};
            maxEmpId = max(maxEmpId, x->id);
        }
        
        int sum = 0;
        vector<bool> visited(maxEmpId+1, false);// wrong as emp numbers are not ordered or logical
        visited[id] = true;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            sum += (mp[x].first);
            
            for(auto y : mp[x].second){
                if(!visited[y]){
                    visited[y] = true;
                    q.push(y);                    
                }
            }
            
        }
        
        return sum;
        
    }
};
