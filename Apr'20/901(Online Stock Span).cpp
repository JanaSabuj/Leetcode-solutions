class StockSpanner {
    stack<pair<int,int>> s;
    int idx;
public:
    StockSpanner() {
        idx = -1;
    }
    
    int next(int price) {
        idx++;// start from 0
        
        int ans;
        if(s.empty()){
            ans = idx + 1;
            s.push({idx, price});
        }else if(price < s.top().second){
            // stop and process
            ans = idx - s.top().first;
            s.push({idx, price});
        }else{
            while(!s.empty() and price >= s.top().second)
                s.pop();
            if(s.empty())
                ans = idx + 1;
            else
                ans = idx - s.top().first;
            
            s.push({idx, price});
        }
        
        return ans;
            
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
