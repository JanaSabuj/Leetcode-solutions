1042. Flower Planting With No Adjacent
Easy

190

234

Add to List

Share
You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

 

Example 1:

Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:

Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]
 

Note:

1 <= N <= 10000
0 <= paths.size <= 20000
No garden has 4 or more paths coming into or leaving it.
It is guaranteed an answer exists.
Accepted
16,775
Submissions
34,864

---------------------------------------------------
class Solution {
public:

	void DFSUtil(int u, int color[]) {
		bool temp[5];
		memset(temp, true, sizeof(temp));
		for (auto v : adj[u]) {
			if (color[v] != 0)
				temp[color[v]] = false;
		}

		for (int i = 1; i <= 4; i++)
			if (temp[i] == true) {
				color[u] = i;
				break;
			}
	}

	void dfs(const vector<vector<int>>& adj, int N, int color[]) {

		memset(color, 0, sizeof(color));
		color[1] = 1;

		for (int i = 1; i <= N; i++)
			if (color[i] == 0) // not colored
				DFSUtil(i, color);
	}
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<vector<int>> adj(N + 1);// start from 1
		// adj matrix
		for (auto edge : paths) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]);
		}

		int color[N + 1];
		dfs(adj, N, color);

		vector<int> ans;
		for(int i = 1; i <= N; i++)
			ans.push_back(color[i]);

		return ans;
	}
};