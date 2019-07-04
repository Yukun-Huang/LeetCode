// 1.从后往前遍历，如果找到一个小于nums[n-1]的数位i，记录当前位置
// 2.从i+1位置开始从前往后遍历，找到一个大于nums[i]的最小数
// 3.将nums[i]与该最小数交换位置，接着把[i+1,n)范围内的数重新排序
// 4.结束

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		bool ok_flag = false;
		for (int i = n - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1]) {
				for (int j = i + 1; j<n; j++) {
					if (nums[j] <= nums[i]) {
						swap(nums, j - 1, i);
						sort(nums.begin() + i + 1, nums.end());
						ok_flag = true;
						break;
					}
				}
				if (!ok_flag) {
					swap(nums, n - 1, i);
					sort(nums.begin() + i + 1, nums.end());
					ok_flag = true;
					break;
				}
			}
			if (ok_flag)
				break;
		}
		if (!ok_flag)
			reverse(nums.begin(), nums.end());
	}

	void swap(vector<int>& nums, int a, int b) {
		int tmp = nums[a];
		nums[a] = nums[b];
		nums[b] = tmp;
	}
};