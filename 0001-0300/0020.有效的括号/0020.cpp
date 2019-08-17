class Solution {
public:
	bool isValid(string s) {
		stack<char> sk;
		for (char c : s) {
			if (c == '(' || c == '[' || c == '{')
				sk.push(c);
			// remember! check stack.empty() before call stack.top()
			else if (!sk.empty() && abs(sk.top() - c) <= 2)  // ascii code
				sk.pop();
			else
				return false;
		}
		if (sk.empty())
			return true;
		else
			return false;
	}
};
