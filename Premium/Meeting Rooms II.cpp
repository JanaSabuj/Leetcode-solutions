Description
中文
English
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Have you met this question in a real interview?  
Example
Example1

Input: intervals = [(0,30),(5,10),(15,20)]
Output: 2
Explanation:
We need two meeting rooms
room1: (0,30)
room2: (5,10),(15,20)
Example2

Input: intervals = [(2,7)]
Output: 1
Explanation: 
Only need one meeting room

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
     
     static bool comp(Interval& lhs, Interval& rhs){
         return lhs.start < rhs.start;
     }
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        if(n == 0)
            return 0;
            
        priority_queue<int, vector<int>, greater<int>> pq;
        int mx = 0;
        for(int i = 0; i < n; i++){
            if(pq.empty()){
                pq.push(intervals[i].end);
            }else if(intervals[i].start > pq.top()){
                // re-use the room
                pq.pop();
                pq.push(intervals[i].end);
            }else{
                pq.push(intervals[i].end);
            }
            
            mx = max(mx, int(pq.size()));
        }
        
        return mx;
    }
};
