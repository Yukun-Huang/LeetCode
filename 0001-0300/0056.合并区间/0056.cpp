class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> output;
		int n = intervals.size();
		if (!n) return output;
		sort(intervals.begin(), intervals.end());
		for (int i = 0; i<n - 1; ++i) {
			if (intervals[i][1] >= intervals[i + 1][0]) {
				intervals[i + 1][0] = intervals[i][0];
				intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
			}
			else {
				output.push_back(intervals[i]);
			}
		}
		output.push_back(intervals.back());
		return output;
	}
};