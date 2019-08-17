class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int p = 0, l = 0, r = n - 1;
		while (p <= r) {
			if (nums[p] == 0)
				swap(nums[p++], nums[l++]);
			else if (nums[p] == 2)
				swap(nums[p], nums[r--]);
			else
				p++;
		}
	}
};