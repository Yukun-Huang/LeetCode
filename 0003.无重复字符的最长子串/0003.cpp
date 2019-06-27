/* 思路:
对字符遍历,记录每个字符的右索引位置.
如果左边界小于等于当前字符对应的右索引位置,说明该字符已经出现,这时候需要更新左边界的值.
否则说明该字符没出现,输出加1.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = {0};    //字符有256个
        int left = 0;        //当前查找的左边界
        int ans = 0;         //最终结果
        for(int i=0;i<s.length();i++)
        {
            if(m[s[i]]==0 || m[s[i]]<left)
            {
                ans = max(ans, i-left+1);
            }
            else
            {
                left = m[s[i]];
            }
            m[s[i]] = i+1;
        }
        return ans;
    }
};
