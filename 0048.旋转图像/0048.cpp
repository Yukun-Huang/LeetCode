// �ⷨ
// 1.�Ծ��󰴲�������������Ϊi����Χ[0, n/2). iʵ����Ҳ����������;
// 2.����ÿ�㰴�б�������������Ϊj����Χ[i, n-i-1);
// 3.�ҵ������ĸ��㣬��˳�򽻻�Ԫ��λ��:
//     pt: (i, j)
//     pr: (j, n-i-1)
//     pb: (n-i-1, n-j-1)
//     pl  (n-j-1, i)
//     swap(pt,pl) -> swap(pl,pb) -> swap(pb,pr) 

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n / 2; ++i)  // ��i��
			for (int j = i; j < n - i - 1; ++j) {
				swap(i, j, n - j - 1, i, matrix);
				swap(n - j - 1, i, n - i - 1, n - j - 1, matrix);
				swap(n - i - 1, n - j - 1, j, n - i - 1, matrix);
			}
	}

	void swap(int r1, int c1, int r2, int c2, vector<vector<int>>& matrix) {
		int temp = matrix[r1][c1];
		matrix[r1][c1] = matrix[r2][c2];
		matrix[r2][c2] = temp;
	}
};