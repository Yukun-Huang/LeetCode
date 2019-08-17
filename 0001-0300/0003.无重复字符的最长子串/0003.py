class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        dic = {}
        l = []
        for c in list(s):
            l.append(c)
            if c not in dic:
                dic[c] = 1
                if len(l) > ans:
                    ans = len(l)
            else:
                while 1:
                    cc = l.pop(0)
                    if cc == c:
                        break
                    else:
                        dic.pop(cc)
        return ans
