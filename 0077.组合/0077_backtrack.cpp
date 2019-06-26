#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	int n;
	int k;
	vector<vector<int>> output;

	vector<vector<int>> combine(int n, int k) {
		this->n = n;
		this->k = k;
		vector<int> curr;
		_backtrack(1, curr);
		return output;
	}

	void _backtrack(int first, vector<int> &res) {
		// if the combination is done
		if (res.size() == this->k) {
			output.push_back(res);
			return;
		}
		for (int i = first; i < n + 1; ++i) {
			// add i into the current combination
			res.push_back(i);
			// use next integers to complete the combination
			_backtrack(i+1, res);
			// backtrack
			res.pop_back();
		}
	}
};


int main() {
	Solution S;
	vector<vector<int>> ans = S.combine(4, 2);
	system("pause");
	return 0;
}