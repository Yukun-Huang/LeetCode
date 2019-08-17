// pair<int, int>�ֱ��Ӧ������͸߶ȱ仯ֵ
class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		int idx = 0;
		int h_last = 0;
		stack<pair<int, int>> sk;
		for (int h : height) {
			if (h < h_last) {
				sk.push(make_pair(idx, h_last - h));
			}
			else if (h > h_last && !sk.empty()) {
				int dh = h - h_last;
				// case 1: ����ջ��
				if (dh <= sk.top().second) {
					ans += (idx - sk.top().first) * dh;
					sk.top().second -= dh;
					if (!sk.top().second)
						sk.pop();
				}
				// case 2: ����ջ��
				else {
					do {
						ans += (idx - sk.top().first) * sk.top().second;
						dh -= sk.top().second;
						sk.pop();
					} while (!sk.empty() && dh >= sk.top().second);
					if (!sk.empty()) {   // ��case 1����ʽһ��
						ans += (idx - sk.top().first) * dh;
						sk.top().second -= dh;
						if (!sk.top().second)
							sk.pop();
					}
				}
			}
			h_last = h;
			idx++;
		}
		return ans;
	}
};