class MedianFinder {
    priority_queue<int> lowers;// maxheap
    priority_queue<int, vector<int>, greater<int>> highers;// minheap        
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void rebalance(){
        int ll = lowers.size();
        int hl = highers.size();
        
        if(ll - hl >= 2){
            // lowers is higher by 2 size 
            highers.push(lowers.top());
            lowers.pop();
        }else if(hl - ll >= 2){
            lowers.push(highers.top());
            highers.pop();
        }
    }
    
    void addNum(int num) {
        // add the num
        if(lowers.size() == 0 || num <= lowers.top())
            lowers.push(num);
        else
            highers.push(num);
        // rebalance the heaps
        rebalance();
    }
    
    double findMedian() {
        // find the median
        if(lowers.size() == highers.size())
            return (double)(lowers.top() + highers.top()) / 2;
        else{
            if(lowers.size() > highers.size())
                return lowers.top();
            else
                return highers.top();
        }
        
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */