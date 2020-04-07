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

	int minMeetingRooms(vector<Interval> &intervals) {
		// Write your code here
		int n = intervals.size();
		if (n == 0)
			return 0;
		vector<pair<int, char>> times;
		for (auto x : intervals) {
			times.push_back({x.start, 'x'});
			times.push_back({x.end, 'y'});
		}

		sort(times.begin(), times.end());

		int ans = 0;
		int cnt = 0;
		for (int i = 0; i < 2 * n; ++i) {
			if (times[i].second == 'x') {
				cnt++;
				ans = max(ans, cnt);
			}
			else
				cnt--;
		}

		return ans;
	}
};
