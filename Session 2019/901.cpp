class StockSpanner {
public:
    stack<int> s;
    
    int idx;
    vector<int> vec;
    StockSpanner() {
        idx = -1;    
    }
    
    int next(int price) {
        idx++;
        vec.push_back(price);
        
        if(idx == 0){
            s.push(-1);
            s.push(idx);
            return 1;
            
        }
           
        if(vec[s.top()] <= price ) {
            while(s.top() != -1 and vec[s.top()] <= price)
                s.pop();
        }
        
        
        int ans = idx - s.top();
        s.push(idx);
        return ans;
         
 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */