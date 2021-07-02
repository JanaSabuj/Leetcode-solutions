typedef pair<int,int> pii;
class Solution {
public:
    class cmp {
        public:
            bool operator()(const pii& p1, const pii& p2){
                return p1.first + p1.second < p2.first + p2.second;
            }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pii, vector<pii>, cmp> pq;// max-heap
        for(auto x: nums1){
            for(auto y: nums2){
                pq.push({x, y});
                if(pq.size() > k)
                    pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            ans.push_back({x.first, x.second});
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
