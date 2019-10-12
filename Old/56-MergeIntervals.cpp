 /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
    static bool compareinterval(Interval i1, Interval i2){
        return i1.start<i2.start ;
    }
    
    vector<Interval> merge(vector<Interval>& vec) {
                int sz=vec.size();
            if(sz<=0) return {};
            
        vector<Interval> ans;
            sort(vec.begin(), vec.end(), compareinterval);
            
        stack<Interval> s;
        s.push(vec[0]);
        
        for(int i=1; i<sz; i++){
            
            Interval x= s.top();
            if(x.end<vec[i].start)
                s.push(vec[i]);
            else if(x.end<vec[i].end){
                x.end=vec[i].end;
                s.pop();
                s.push(x);
            }
        }
        
        while(!s.empty()){
            Interval x= s.top();
            ans.push_back(x);
            s.pop();
        }
        
        sort(ans.begin(), ans.end(), compareinterval);
        return ans;
        
    }
    
    
};