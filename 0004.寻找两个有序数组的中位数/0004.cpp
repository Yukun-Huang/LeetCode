#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		// special case: size = 0
		if (nums1.size() == 0)
			return get_median(nums2);
		else if (nums2.size() == 0)
			return get_median(nums1);
		// swap
		if (nums2.size() < nums1.size()) {
			vector<int> tmp = nums1;
			nums1 = nums2;
			nums2 = tmp;
		}
		int m = nums1.size(), n = nums2.size();
		assert(n >= m);
		int half_len = (m + n + 1) / 2;
		int min_i = 0, max_i = m;
		while (min_i <= max_i) {

			int i = (min_i + max_i) / 2;
			int j = half_len - i;

			if (i > 0 && j < n && nums1[i - 1] > nums2[j]) {
				max_i = i - 1;
			}
			else if (i < m && j > 0 && nums1[i] < nums2[j - 1]) {
				min_i = i + 1;
			}
			else {
				int maxLeft = 0;
				if (i == 0)
					maxLeft = nums2[j - 1];
				else if (j == 0)
					maxLeft = nums1[i - 1];
				else
					maxLeft = max(nums1[i - 1], nums2[j - 1]);
				int minRight = 0;
				if (i == m)
					minRight = nums2[j];
				else if (j == n)
					minRight = nums1[i];
				else
					minRight = min(nums1[i], nums2[j]);
				if ((m + n) % 2)
					return maxLeft;
				else
					return (maxLeft + minRight) / 2.0;
			}
		}
		assert(0);
		return 0;
	}

	double get_median(vector<int>& nums) {
		int n = nums.size();
		assert(n > 0);
		if (n % 2)
			return nums[(n - 1) / 2];
		else
			return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
	}
};


int main() {
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(5);
	nums1.push_back(6);

	vector<int> nums2;
	nums2.push_back(4);

	Solution S;
	cout << S.findMedianSortedArrays(nums1, nums2) << endl;
	system("pause");
	return 0;
}