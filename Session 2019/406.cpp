class Solution {
public:

	static bool comp(const vector<int>& v1, const vector<int>& v2) {
		// concise comparator function
		return v1[0] > v2[0] || (v1[0] == v2[0] and v1[1] < v2[1]);
	}

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), comp);
		vector<vector<int>> ans;

		int n = people.size();
		if (n == 0)
			return {};

		int top = people[0][0];// assuming atleast 1 element

		for (int i = 0; i < n; i++)
			if (people[i][0] == top)
				ans.push_back(people[i]);// tallest people retain their positon acc to their k values
			else
				ans.insert(ans.begin() + people[i][1] , people[i]);//insert the rest acc to their k values

		return ans;
	}
};
