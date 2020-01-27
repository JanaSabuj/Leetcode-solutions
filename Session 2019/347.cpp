// 347. Top K Frequent Elements
// Medium

// 2253

// 150

// Add to List

// Share
// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Note:

// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


// ------------------------------------------------------
// Using vec of vects
class Solution {
public:
    
    struct comp{
        bool operator()(const vector<int>& v1, const vector<int>& v2){
            return v2[1] < v1[1];// MinHeap
        }
    };
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto x: nums)
            mp[x]++;
        
        vector<vector<int>> vec;
        for(auto kv: mp){
            vector<int> t = {kv.first, kv.second};
            vec.push_back(t);
        }
        
        priority_queue<vector<int>, vector<vector<int>>, comp> heap;
        
        for(auto tuple: vec){
            heap.push(tuple);
            if(heap.size() > k)
                heap.pop();
        }
        
        vector<int> ans;
        while(!heap.empty()){
            ans.push_back(heap.top()[0]);
            heap.pop();
        }
        
        return ans;
        
    }
};