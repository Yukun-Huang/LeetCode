// 转换为直方图最大矩形的形式

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		int rows = matrix.size(), cols = matrix[0].size();
		int maxArea = 0;
		vector<int> vRow(cols, 0);
		// 初始化
		for (int i = 0; i<cols; ++i) {
			if (matrix[0][i] == '0')
				vRow[i] = 0;
			else
				vRow[i] = 1;

		}
		maxArea = max(maxArea, monoStack(vRow));
		// 行扫描
		for (int i = 1; i<rows; ++i) {
			for (int j = 0; j<cols; ++j) {
				if (matrix[i][j] == '0')
					vRow[j] = 0;
				else
					vRow[j] += 1;
			}
			maxArea = max(maxArea, monoStack(vRow));
		}
		return maxArea;
	}

	int monoStack(vector<int>& heights) {
		int n = heights.size();
		int maxArea = 0;
		stack<int> s;
		s.push(-1);
		// 遍历所有元素
		for (int i = 0; i<n; ++i) {
			while (s.top() != -1 && heights[s.top()] >= heights[i]) {
				int tmp = s.top();
				s.pop();
				maxArea = max(maxArea, heights[tmp] * (i - 1 - s.top()));
			}
			s.push(i);
		}
		// 剩余的元素出栈，结算
		while (s.top() != -1) {
			int tmp = s.top();
			s.pop();
			maxArea = max(maxArea, heights[tmp] * (n - s.top() - 1));
		}
		return maxArea;
	}
};
