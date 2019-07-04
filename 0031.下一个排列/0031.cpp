// 1.�Ӻ���ǰ����������ҵ�һ��С��nums[n-1]����λi����¼��ǰλ��
// 2.��i+1λ�ÿ�ʼ��ǰ����������ҵ�һ������nums[i]����С��
// 3.��nums[i]�����С������λ�ã����Ű�[i+1,n)��Χ�ڵ�����������
// 4.����

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