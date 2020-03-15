class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        bool visited[n];
        memset(visited, false, sizeof(visited));

        queue<pair<int,int>> q;
        q.push({start, 0});
        visited[start] = true;

        while(!q.empty()){
            pair<int,int> p = q.front(); q.pop();
            int idx = p.first;
            int steps = p.second;

            if(arr[idx] == 0)
                return true;

            int a = idx + arr[idx];
            int b = idx - arr[idx];

            if((a >= 0 and a < n) and !visited[a]){
                q.push({a, steps + 1});
                visited[a] = true;
            }
            
            if((b >= 0 and b < n) and !visited[b]){
                q.push({b, steps + 1});
                visited[b] = true;
            }
        }

        return false;

    }
};
