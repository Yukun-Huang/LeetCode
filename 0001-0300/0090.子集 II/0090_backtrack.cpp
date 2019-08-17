#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;


class Solution {
	int n;
	vector<vector<int>> output;

public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		n = nums.size();
		sort(nums.begin(), nums.end());
		vector<int> curr;
		_backtrack(0, curr, nums);
		return output;
	}

	void _backtrack(int first, vector<int> &res, vector<int>& nums) {
		output.push_back(res);
		for (int i = first; i < n; ++i) {
			if (i > first && nums[i] == nums[i - 1])
				continue;
			res.push_back(nums[i]);
			_backtrack(i + 1, res, nums);
			res.pop_back();
		}
	}
};


int main() {
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(2);

	Solution S;
	vector<vector<int>> ans = S.subsetsWithDup(input);
	system("pause");
	return 0;
}