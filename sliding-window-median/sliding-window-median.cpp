class Solution {
public:
    void add(int val, int idx, set<pair<int, int>>& lowers, set<pair<int, int>>& highers) {
	if (lowers.size() == 0 || val < lowers.rbegin()->first)
		lowers.insert({val, idx});
	else
		highers.insert({val, idx});
}

void dlete(int val, int idx, set<pair<int, int>>& lowers, set<pair<int, int>>& highers) {
	if (lowers.find({val, idx}) != lowers.end())
		lowers.erase({val, idx});
	else
		highers.erase({val, idx});
}

void rebalance(set<pair<int, int>>& lowers, set<pair<int, int>>& highers) {
	int ll = lowers.size();
	int hl = highers.size();

	if (ll - hl >= 2) {
		highers.insert({lowers.rbegin()->first, lowers.rbegin()->second});
		lowers.erase(*lowers.rbegin());
	} else if (hl - ll >= 2) {
		lowers.insert({highers.begin()->first, highers.begin()->second});
		highers.erase(*highers.begin());
	}
}

double findMedian(set<pair<int, int>>& lowers, set<pair<int, int>>& highers) {
	if (lowers.size() == highers.size())
		return  ((long long int)lowers.rbegin()->first + (long long int)highers.begin()->first) * 1.0 / 2;
	else if (lowers.size() > highers.size())
		return lowers.rbegin()->first;
	else
		return highers.begin()->first;
}
    vector<double> medianSlidingWindow(vector<int>& arr, int k) {
        set<pair<int, int>> lowers;
	    set<pair<int, int>> highers;
        int n = arr.size();
        
        vector<double> ans;
        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            add(val, i, lowers, highers);
            if (i > k - 1)
                dlete(arr[i - k], i - k, lowers, highers);
            rebalance(lowers, highers);

            if (i >= k - 1)
                ans.push_back(findMedian(lowers, highers));
        }
        
        return ans;
    }
};