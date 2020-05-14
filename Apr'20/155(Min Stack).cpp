class MinStack {
    stack<int> s;
    stack<int> mix;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            mix.push(x);
        }else{
            s.push(x);
            if(x <= mix.top())
                mix.push(x);
        }
            
    }
    
    void pop() {
        if(s.empty())
            return;
        
        int x = s.top();
        if(x == mix.top()){
            mix.pop();
        }        
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(mix.empty())
            return -1;
        return mix.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
