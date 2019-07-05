class Solution {

public:
	int longestValidParentheses(string s) {
		int ans = 0;
		int idx = 0;
		stack<pair<char, int>> sk;
		sk.push(make_pair<char, int>('b', 0));
		for (char c : s) {
			idx++;
			if (c == '(')
				sk.push(make_pair(c, idx));
			else {
				pair<char, int> p = sk.top();
				if (p.first == '(') {
					sk.pop();
					ans = max(ans, idx - sk.top().second);
				}
				else {
					assert(p.first == 'b');
					sk.top().second = idx;
				}
			}
		}
		return ans;
	}
};

