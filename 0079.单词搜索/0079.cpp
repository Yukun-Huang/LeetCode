class Solution {
public:
	int maxR, maxC;

	bool exist(vector<vector<char>>& board, string word) {
		if (!board.size() || !board[0].size())
			return false;
		maxR = board.size(), maxC = board[0].size();
		int pathLength = 0;
		vector<vector<bool>> visited(maxR, vector<bool>(maxC, false));
		for (int i = 0; i<maxR; ++i)
			for (int j = 0; j<maxC; ++j) {
				if (backtrack(board, visited, word, pathLength, i, j))
					return true;
			}
		return false;
	}

	bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int& len, int r, int c) {
		if (len == word.length())
			return true;
		bool exist_flag = false;
		if (r >= 0 && c >= 0 && r<maxR && c<maxC && (!visited[r][c]) && (board[r][c] == word[len])) {
			len++;
			visited[r][c] = true;
			exist_flag = backtrack(board, visited, word, len, r - 1, c) ||
				backtrack(board, visited, word, len, r + 1, c) ||
				backtrack(board, visited, word, len, r, c - 1) ||
				backtrack(board, visited, word, len, r, c + 1);
			if (!exist_flag) {
				len--;
				visited[r][c] = false;
			}
		}
		return exist_flag;
	}
};