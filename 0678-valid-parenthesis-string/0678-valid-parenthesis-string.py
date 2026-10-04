class Solution:
    def checkValidString(self, s: str) -> bool:
        min_open = 0
        max_open = 0

        for ch in s:
            if ch == '(':
                max_open += 1
                min_open += 1
            elif ch == ')':
                max_open -= 1
                min_open -= 1
            elif ch == '*':
                min_open -= 1
                max_open += 1
            
            if max_open < 0:
                return False
            
            if min_open < 0:
                min_open = 0
        
        return min_open == 0