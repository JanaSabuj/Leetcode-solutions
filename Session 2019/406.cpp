406. Queue Reconstruction by Height
Medium

2092

248

Add to List

Share
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 

Accepted
103,299
Submissions
165,538
-----------------------------------------------------
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
