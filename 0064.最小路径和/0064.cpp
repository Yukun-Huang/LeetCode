class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (!m) return 0;
		int n = grid[0].size();
		if (!n) return 0;
		for (int i = 0; i<m; ++i)
			for (int j = 0; j<n; ++j) {
				if (!i && !j) continue;
				else if (!i) grid[i][j] += grid[i][j - 1];
				else if (!j) grid[i][j] += grid[i - 1][j];
				else {
					grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
				}
			}
		return grid[m - 1][n - 1];
	}
};