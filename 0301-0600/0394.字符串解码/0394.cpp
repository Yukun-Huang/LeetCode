// 找到子问题，递归

class Solution {
public:
    int idx;
    string decodeString(string s) {
        idx = 0;
        return helper(s);
    }
    
    string helper(string& s){
        string res = "";
        int cnt = 0;
        while (idx < s.length()){
            char c = s[idx];
            if (c >= '0' && c <= '9'){
                idx++;
                cnt = 10*cnt + int(c-'0');
            }
            else if (c == '['){
                idx++;
                string tmp = helper(s);
                for (int i=0; i<cnt; ++i)
                    res += tmp;
                cnt = 0;
            }
            else if (c == ']'){
                idx++;
                return res;
            }
            else{
                idx++;
                res += c;
            }
        }
        return res;
    }
};