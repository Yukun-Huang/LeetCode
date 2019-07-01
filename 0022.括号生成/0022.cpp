class Solution {
	vector<string> output;
	vector<char> sol;
	int n;

public:
	vector<string> generateParenthesis(int n) {
		this->n = n;
		backtrack(n, 0, sol);
		return output;
	}

	void backtrack(int nLeftPar, int nRightPar, vector<char> &sol) {
		if (sol.size() == 2 * n) {
			output.push_back(string(sol.begin(), sol.end()));
			return;
		}
		if (nLeftPar) {
			sol.push_back('(');
			backtrack(nLeftPar - 1, nRightPar + 1, sol);
			sol.pop_back();
		}
		if (nRightPar) {
			sol.push_back(')');
			backtrack(nLeftPar, nRightPar - 1, sol);
			sol.pop_back();
		}
	}
};