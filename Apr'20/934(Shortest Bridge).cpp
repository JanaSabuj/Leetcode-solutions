class Solution {
    vector<int> visited;
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    queue<int> q;

public:

    void dfs(int i, int j, vector<vector<int>>& A) {
        if (i < 0 or i >= n or j < 0 or j >= m or visited[i * m + j] or A[i][j] == 0)
            return;
        visited[i * m + j] = true;
        A[i][j] = 2;
        q.push(i * m + j);

        for (int k = 0; k < 4; k++) {
            int r = i + dx[k];
            int c = j + dy[k];
            dfs(r, c, A);
        }
    }

    int shortestBridge(vector<vector<int>>& A) {
        n = A.size();
        if (n == 0)
            return 0;
        m = A[0].size();

        visited.assign( n * m, 0 );// false

        // dfs the 1st island
        bool found = false;
        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < m; j++) {                
                
                if (A[i][j] == 1) {
                    
                    found = true;
                    dfs(i, j, A);                    
                    break;
                }
            }
            
            if(found)
                break;
        }
        
        
         
        // start bfs
        int steps = 0;
        while (!q.empty()) {

            // level by level
            int xx = q.size();
            for (int i = 0; i < xx ; i++) {
                int f = q.front();
                q.pop();
                int x = f / m;
                int y = f % m;
                
                cout << x << " " << y << " " << A[x][y] << " " << steps <<  endl;
                
                if (A[x][y] == 1){
                    cout << x << " " << y << " x " << steps;
                    return steps - 1;
                }

                for (int k = 0; k < 4; k++) {
                    int r = x + dx[k];
                    int c = y + dy[k];

                    if (r >= 0 and r < n and c >= 0 and c < m and !visited[r * m + c]) {
                        q.push(r * m + c);
                        visited[r * m + c] = true;
                    }
                }

            }

            steps++;

        }

        return -1;

    }
};
