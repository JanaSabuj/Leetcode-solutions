class Solution {
public:
    class cmp{
        public:
        bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
            return p1.first > p2.first;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto x: nums)
            mp[x]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;// max - heap
        
        for(auto pp: mp){
            int x = pp.first;
            int y = pp.second;
            
            cout << x << " " << y << endl;
            // pair<int,int> p = {y,x};
            pq.push({y,x});
            if(pq.size() > k)
                pq.pop();            
        }
        
        vector<int> req;
        while(!pq.empty()){
            req.push_back(pq.top().second);
            pq.pop();
        }
        
        return req;        
    }
};
//