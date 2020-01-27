// 692. Top K Frequent Words
// Medium

// 1213

// 109

// Add to List

// Share
// Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.
// Accepted
// 113,878
// Submissions
// 233,139


// -------------------------------------------------------------
class Solution {
public:
    
    struct comp{
        bool operator()(const pair<string,int>& p1, const pair<string,int>& p2){
            // p2 always on top of heap if
            if(p1.second == p2.second)
                return p2.first > p1.first;
            else
                return p2.second < p1.second;
        }  
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto x: words)
            mp[x]++;
        priority_queue<pair<string,int>, vector<pair<string,int>>, comp> heap;
        
        for(auto kv: mp){
            heap.push({kv.first, kv.second});
            if(heap.size() > k)
                heap.pop();
        }
        
        vector<string> ans;
        while(!heap.empty()){
            ans.push_back(heap.top().first);
            heap.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};