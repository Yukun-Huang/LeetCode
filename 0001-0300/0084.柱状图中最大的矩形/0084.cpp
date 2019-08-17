/* 单调栈
栈内按从小到大排序，出栈时结算。结算时，高度=出栈元素高度，范围=出栈元素可达的最大范围，
即[出栈后栈顶索引,当前索引]。如果已经遍历完成，则当前索引等于结尾索引。
步骤：
1.初始化栈底。
2.遍历。若不符合顺序或者栈到底，一直出栈直到满足条件。然后入栈。
3.剩余元素依次出栈。
*/

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		int maxArea = 0;
		stack<int> s;
		s.push(-1);
		for (int i = 0; i<n; ++i) {  // 遍历所有元素
			while (s.top() != -1 && heights[s.top()] >= heights[i]) {
				int tmp = s.top();
				s.pop();
				maxArea = max(maxArea, heights[tmp] * (i - 1 - s.top()));
			}
			s.push(i);
		}
		while (s.top() != -1) {  // 剩余的元素出栈，结算
			int tmp = s.top();
			s.pop();
			maxArea = max(maxArea, heights[tmp] * (n - 1 - s.top()));
		}
		return maxArea;
	}
};

