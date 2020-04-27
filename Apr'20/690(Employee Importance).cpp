/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, vector<int>> mp;
    unordered_map<int,int> imp;
    // int visited[2007];
    
    void dfs(int id, int & total){
        // visited[id] = true;
        total += imp[id];
        
        for(auto x: mp[id]){            
                dfs(x, total);
        }
    }
        
    int getImportance(vector<Employee*> emps, int id) {
        
        mp.clear();
        imp.clear();
        // memset(visited, false, sizeof(visited));
        
        for(auto emp: emps){
            mp[emp->id] = emp->subordinates;
            imp[emp->id] = emp->importance;
        }
        
        int total = 0;
        dfs(id, total);
        
        return total;
    }
};
