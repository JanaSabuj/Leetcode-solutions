210. Course Schedule II
Medium

1503

101

Add to List

Share
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
Accepted
205,074
Submissions
543,068
----------------------------------------------------------------------------------

class Solution {
public:
    
    vector<int> Kahn(vector<vector<int>>& adj, vector<int>& indegree, int n){
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        int cnt = 0;
        vector<int> order;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;
            
            order.push_back(u);
            
            for(auto v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        
        reverse(order.begin(), order.end());// My order will be reverse of Topo Sort
        
        // return order; MISTAKE - always check for DAG first
        if(cnt != n)
            return {};
        else
            return order;
        
        
    }
    
    
    vector<int> findOrder(int n, vector<vector<int>>& prereqs) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        
        for(auto edge: prereqs){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;    
        }
        
        return Kahn(adj ,indegree, n);
    }
};