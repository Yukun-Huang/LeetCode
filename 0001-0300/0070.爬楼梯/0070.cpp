class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2) return n;
		int a1 = 1, a2 = 2, a3 = 0;
		for (int i = 3; i <= n; i++) {
			a3 = a1 + a2;
			a1 = a2;
			a2 = a3;
		}
		return a3;
	}

	int climbStairs_TLE(int n) {
		if (n <= 2) return n;
		return climbStairs(n - 1) + climbStairs(n - 2);
	}
};