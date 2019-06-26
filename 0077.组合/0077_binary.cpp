#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	int n;
	int k;

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> output;
		vector<int> nums;
		vector<int> sub_nums;
		// init first combination
		for (int i = 1; i <= k; ++i) {
			nums.push_back(i);
		}
		nums.push_back(n + 1);
		// iteration
		int j = 0;
		while (j < k) {
			// add current combination
			sub_nums.assign(nums.begin(), nums.begin() + k);
			output.push_back(sub_nums);
			// increase first nums[j] by one
			// if nums[j] + 1 != nums[j + 1]
			j = 0;
			while (j < k && nums[j + 1] == nums[j] + 1) {
				nums[j] = j + 1;
				j++;
			}
			nums[j] += 1;
		}
		return output;
	}
};


int main() {
	Solution S;
	vector<vector<int>> ans = S.combine(4, 2);
	system("pause");
	return 0;
}