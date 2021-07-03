class Solution {
public:
       int minLenPath(string& beginWord, string& endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end())
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        dict.erase(beginWord);

        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            if (x.first == endWord)
                return x.second;

            // check its children
            string curr = x.first;
            for (int i = 0; i < (int)curr.size(); i++) {
                char old = curr[i];

                for (int j = 0; j < 26; j++) {
                    if ((j + 'a') == old) continue;
                    curr[i] = (j + 'a');

                    if (dict.find(curr) != dict.end()) {
                        q.push({curr, x.second + 1});
                        dict.erase(curr);
                    }
                }

                curr[i] = old;
            }
        }

        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int k = minLenPath(beginWord, endWord, wordList);
        return k;
    }
};