class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        self.digits = digits
        self.output = []
        self.sol = []
        self.n = len(digits)
        if not self.n:
            return self.output
        self.state = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }
        self.backtrack(first=0)
        return self.output
        
    def backtrack(self, first):
        if len(self.sol) == self.n:
            self.output.append("".join(self.sol))
            return
        for item in self.state[self.digits[first]]:
            self.sol.append(item)
            self.backtrack(first+1)
            self.sol.pop()

            
            