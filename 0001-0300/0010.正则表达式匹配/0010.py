import re

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        pattern = re.compile(p)  # 声明为re可接受模式

        str_ = re.findall(pattern, s)
        for i in str_:
            if i == s:
                return True
        return False