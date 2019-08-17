#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>
#include <functional>

#define FOR(i,n) for (int i = 1 ; i <= n ; ++i)
#define RFOR(i,n) for (int i = n ; i >= 1 ; --i)
#define REP(i,n) for (int i = 0 ; i < n ; ++i)

#define MOD 1000000007

using namespace std;

typedef unsigned long long uLL;
typedef long long LL;

// 时间复杂度为O(n^2)

// 该方案因为引入了多余的字符串处理而超时
class Solution_slow {
public:
	int n;

	string longestPalindrome(string s) {
		n = s.size();
		int max_len = 0;
		string max_substr = "";
		for (int i = 0; i < n; ++i) {
			// check odd
			string substr(1, s[i]);
			int len = check_len_odd(i, substr, s);
			if (len > max_len) {
				max_len = len;
				max_substr = substr;
			}
			// check even
			substr = "";
			len = check_len_even(i, substr, s);
			if (len > max_len) {
				max_len = len;
				max_substr = substr;
			}
		}
		return max_substr;
	}

	int check_len_odd(int i, string &substr, string &s) {
		int count = 1;
		int left = i - count, right = i + count;
		while (left >= 0 && right < n && s[left] == s[right]) {
			substr = s[left] + substr + s[right];
			count += 2;
			left--; right++;
			//cout << substr << endl;
		}
		return count;
	}

	int check_len_even(int i, string &substr, string &s) {
		int count = 0;
		int left = i - count, right = i + 1 + count;
		while (left >= 0 && right < n && s[left] == s[right]) {
			substr = s[left] + substr + s[right];
			count += 2;
			left--; right++;
			//cout << substr << endl;
		}
		return count;
	}
};

// 该方案移除了多余的字符串处理,只在最后返回时提取字串
class Solution {
public:
	int n;
	string longestPalindrome(string s) {
		n = s.size();
		int len1 = 0;
		int len2 = 0;
		int len = 0;
		int max_i = 0;
		int max_len = 0;
		for (int i = 0; i < n; ++i) {
			// check
			len1 = check_len_odd(i, s);
			len2 = check_len_even(i, s);
			len = max(len1, len2);
			if (len > max_len) {
				max_i = i;
				max_len = len;
			}
		}
		if (max_len == 0)
			return string("");
		if (max_len % 2) {
			int left = max_i - max_len / 2;
			return s.substr(left, max_len);
		}
		else {
			int left = max_i + 1 - max_len / 2;
			return s.substr(left, max_len);
		}
	}

	int check_len_odd(int i, string &s) {
		int count = 1;
		int left = i - count, right = i + count;
		while (left >= 0 && right < n && s[left] == s[right]) {
			count += 2;
			left--; right++;
		}
		return count;
	}

	int check_len_even(int i, string &s) {
		int count = 0;
		int left = i - count, right = i + 1 + count;
		while (left >= 0 && right < n && s[left] == s[right]) {
			count += 2;
			left--; right++;
		}
		return count;
	}
};


int main() {
	string s = "ddddssssasad3212fdasfds123213";
	Solution S;
	string ans = S.longestPalindrome(s);
	cout << ans << endl;
	system("pause");
	return 0;
}