/**
 * Definition of Interval:
 * class Interval {
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
     * @return: if a person could attend all meetings
     */
    bool isOverlap(const Interval& x, const Interval& y) {
        int a = max(x.start, y.start);
        int b = min(x.end, y.end);

        return a < b;
    }
    
    static bool comp(const Interval& x, const Interval& y){
        return x.start < y.start;
    }
    

    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        if (n == 0)
            return true;
        Interval t = intervals[0];

        for (int i = 1; i < n; i++) {
            if (isOverlap(t, intervals[i]))
                return false;
            else {

                t = intervals[i];
            }
        }

        return true;

    }
};
