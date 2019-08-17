class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		int max_size = 0;
		int left = 0, right = n - 1;
		while (left < right) {
			max_size = max(max_size, (right - left)*min(height[left], height[right]));
			if (height[left] > height[right])
				right--;
			else if (height[left] < height[right])
				left++;
			else {
				left++; right--;
			}
		}
		return max_size;
	}
};