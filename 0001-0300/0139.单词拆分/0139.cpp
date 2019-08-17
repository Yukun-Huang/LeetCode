// 递归解法的思路：将原问题划分为多个子问题。若前缀子串在字典中，且后续部分（子问题）的递归结果为true，则结果为true。
// DP方案也是一样的思路，只是从自底而上的角度去实现。

class Solution_dp {
public:
   bool wordBreak(string s, vector<string>& wordDict) {
       vector<bool> dp(s.size() + 1, false);
       dp[0] = true;
       for(int i = 1; i < dp.size(); i++)
           for(string &w : wordDict)
               if(i >= w.size() && dp[i - w.size()] && s.substr(i - w.size(), w.size()) == w) {
                   dp[i] = true;
                   break;
               }
       return dp.back();
    }
};


class Solution_memo {
public:
    set<string> words;
    vector<int> memo;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size()+1, -1);
        for (string word : wordDict)
            words.insert(word);
        return _wordBreak(s, 0);
    }
    
    bool _wordBreak(string &s, int start){
        if (start == s.length())
            return true;
        if (memo[start] != -1)
            return bool(memo[start]);
        for (int end=start; end<s.length(); end++){
            if (words.count(s.substr(start, end-start+1)) && _wordBreak(s, end+1)) {
                memo[end] = 1;
                return true;
            }
        }
        memo[start] = 0;
        return false;
    }
};


class Solution_bruteForce {  // TLE
public:
    set<string> words;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict)
            words.insert(word);
        return _wordBreak(s, 0);
    }
    
    bool _wordBreak(string &s, int start){
        if (start == s.length())
            return true;
        for (int end=start; end<s.length(); end++){
            if (words.count(s.substr(start, end-start+1)) && _wordBreak(s, end+1)) {
                return true;
            }
        }
        return false;
    }
};