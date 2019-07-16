// 思路，滑动窗口法

class Solution {
public:
	string minWindow(string s, string t) {
		string ans = "";
		int minLen = s.length();
		int rec[256] = { 0 };
		int match_cnt = 0;
		for (char c : t)  rec[c]++;
		for (int l = 0, r = 0; r<s.size(); ++r) {
			if (--rec[s[r]] >= 0) match_cnt++;
			while (match_cnt == t.size()) {
				if (r - l + 1 <= minLen) {
					minLen = r - l + 1;
					ans = s.substr(l, r - l + 1);
				}
				if (++rec[s[l]] > 0) match_cnt--;
				l++;
			}
		}
		return ans;
	}
};