207. Course Schedule
Medium

2732

141

Add to List

Share
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
-----------------------------------------------------------------------------------

class Solution {
public:
    
    void DFSUtil(int x, vector<int> adj[], int inside[], int outside[], bool visited[], int &time){
        visited[x] = true;
        inside[x] = ++time;
        
        for(auto u : adj[x])
            if(!visited[u])
                DFSUtil(u,adj,inside,outside,visited, time);
        
        outside[x] = ++time;
    }
    
    bool isDAG(vector<int> adj[], int V){
        int inside[V];
        int outside[V];
        
        bool visited[V];
        memset(visited,0,sizeof(visited));
        
        int time = 0;
        
        for(int i = 0; i < V; i++)
            if(!visited[i])
                DFSUtil(i,adj,inside,outside,visited, time);
        
        for(int u = 0; u < V; u++){
            for(auto v: adj[u]){
                if(outside[u] <= outside[v]) // condition that violates DAG - back edge condition
                    return false;
            }
        }
        
        return true;
            
        
    }
    
    
    bool canFinish(int V, vector<vector<int>>& prereqs) {
        vector<int> adj[V];
        for(auto edge : prereqs)
            adj[edge[0]].push_back(edge[1]);
        
        if(isDAG(adj,V))
            return true;
        else
            return false;
    }
};