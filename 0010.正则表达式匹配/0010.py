import re

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        pattern = re.compile(p)  # ����Ϊre�ɽ���ģʽ

        str_ = re.findall(pattern, s)
        for i in str_:
            if i == s:
                return True
        return False