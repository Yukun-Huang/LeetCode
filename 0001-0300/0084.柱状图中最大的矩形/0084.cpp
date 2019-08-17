/* ����ջ
ջ�ڰ���С�������򣬳�ջʱ���㡣����ʱ���߶�=��ջԪ�ظ߶ȣ���Χ=��ջԪ�ؿɴ�����Χ��
��[��ջ��ջ������,��ǰ����]������Ѿ�������ɣ���ǰ�������ڽ�β������
���裺
1.��ʼ��ջ�ס�
2.��������������˳�����ջ���ף�һֱ��ջֱ������������Ȼ����ջ��
3.ʣ��Ԫ�����γ�ջ��
*/

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		int maxArea = 0;
		stack<int> s;
		s.push(-1);
		for (int i = 0; i<n; ++i) {  // ��������Ԫ��
			while (s.top() != -1 && heights[s.top()] >= heights[i]) {
				int tmp = s.top();
				s.pop();
				maxArea = max(maxArea, heights[tmp] * (i - 1 - s.top()));
			}
			s.push(i);
		}
		while (s.top() != -1) {  // ʣ���Ԫ�س�ջ������
			int tmp = s.top();
			s.pop();
			maxArea = max(maxArea, heights[tmp] * (n - 1 - s.top()));
		}
		return maxArea;
	}
};

