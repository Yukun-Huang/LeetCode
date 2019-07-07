
class Solution {
public:
	int uniquePaths(int m, int n) {
		m = long(m);
		n = long(n);
		return int(combination(m + n - 2, m - 1));
	}

	long combination(long n, long k) {
		k = min(k, n - k);
		long A = 1L;
		for (long i = 1L; i <= k; ++i, --n) {
			A *= n;
			A /= i;
		}
		return A;
	}
};


class Solution_withGCD {
public:
	int uniquePaths(int m, int n) {
		m = long(m);
		n = long(n);
		return int(combination(m + n - 2, m - 1));
	}

	long gcd(long a, long b) {
		return !b ? a : gcd(b, a%b);
	}

	long combination(long n, long k) {
		k = min(k, n - k);
		long A = 1L, C;
		for (long i = 1L; i <= k; ++i, --n) {
			C = gcd(i, n);
			A *= n / C;
			A /= i / C;
		}
		return A;
	}
};

