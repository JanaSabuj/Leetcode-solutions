class Solution {
public:
    vector<vector<string>> globalAns;
    unordered_map<string, int> depth;
    unordered_map<string, vector<string>> adj;

    int minLenPath(string& beginWord, string& endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end())
            return 0;

        queue<string> q;
        q.push(beginWord);
        depth[beginWord] = 0;

        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            string currWord = x;
            int currDepth = depth[currWord];

            if (currWord == endWord)
                return currDepth;

            // check its children
            for (int i = 0; i < (int)currWord.size(); i++) {
                char old = currWord[i];

                for (int j = 0; j < 26; j++) {
                    if ((j + 'a') == old) continue;
                    currWord[i] = (j + 'a');
                    
                    if(dict.find(currWord) == dict.end()) continue;// only if valid word
                    
                    if (depth.find(currWord) == depth.end()) {                        
                        depth[currWord] = currDepth + 1;
                        adj[x].push_back(currWord);
                        q.push(currWord);
                    } else {
                        if (depth[currWord] == currDepth + 1) {
                            adj[x].push_back(currWord);
                        }
                    }
                }

                currWord[i] = old;
            }
        }

        return 0;
    }

    void dfs(string currWord, string& endWord, int k, vector<string>& path) {
        path.push_back(currWord);

        if (k == 0) {
            if (currWord == endWord) {
                globalAns.push_back(path);             
            }
            
            path.pop_back();
            return;
        }

        for (auto u : adj[currWord])
            dfs(u, endWord, k - 1, path);

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
    vector<string>& wordList) {
        // 1 - find min length of path k
        int k = minLenPath(beginWord, endWord, wordList);

        // 2 - traverse all paths of length k and print all paths ending with endWord
        if (k == 0)
            return {};
        
        cout << k << endl;
        vector<string> path;
        dfs(beginWord, endWord, k, path);

        return globalAns;
    }
};