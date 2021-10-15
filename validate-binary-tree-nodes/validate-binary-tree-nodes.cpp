typedef vector<int> vi;
class Solution {
public:
    bool dfs(int x, vi& leftChild, vi& rightChild, vi& vis, int& cnt){
        if(x == -1)
            return true;
        if(vis[x]) return false;

        vis[x] = 1;
        cnt++;
        return dfs(leftChild[x], leftChild, rightChild, vis, cnt) && dfs(rightChild[x], leftChild, rightChild, vis, cnt);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vi indeg(n, 0);
        for (int i = 0; i < n; ++i){
            if(leftChild[i] != -1 and ++indeg[leftChild[i]] > 1) return false;
            if(rightChild[i] != -1 and ++indeg[rightChild[i]] > 1) return false;
        }

        int root = -1;
        for (int i = 0; i < n; ++i){
            if(indeg[i] == 0){
                // poss root
                if(root != -1) return false;
                root = i;
            }
        }

        if(root == -1) return false;

        int cnt = 0;
        vi vis(n, 0);
        return dfs(root, leftChild, rightChild, vis, cnt) && cnt == n;

    }
};