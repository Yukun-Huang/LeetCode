// »ØËÝ·¨

class Solution {

public:
	int n;
	vector<vector<int>> ans;

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		n = candidates.size();
		vector<int> sol;
		_recursive(0, target, sol, candidates);
		return ans;
	}

	void _recursive(int choose, int target, vector<int>& sol, vector<int>& candidates) {
		if (target == 0) {
			ans.push_back(sol);
			return;
		}
		else if (target < 0)
			return;

		for (int i = choose; i < n; ++i) {
			sol.push_back(candidates[i]);
			_recursive(i, target - candidates[i], sol, candidates);
			sol.pop_back();
		}
	}
};