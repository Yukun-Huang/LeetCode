/*
从右上角的数开始，做如下判断：
    a.若该数等于target，则返回true
    b.若该数小于target，排除当前行
    c.若该数大于target，排除当前列
  若所有行列均被排除，则返回false
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nR = matrix.size();
        if (!nR) return false;
        int nC = matrix[0].size();
        int r = 0, c = nC-1;
        while (r<nR && c>=0){
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target)
                r++;
            else
                c--;
        }
        return false;
    }
};
