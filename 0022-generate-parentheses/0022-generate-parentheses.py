class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        result = []
        def backtrack(curr_str , openCount , closeCount):
            if len(curr_str) == 2 * n:
                result.append(curr_str)
                return
            if openCount < n:
                backtrack(curr_str + "(" , openCount + 1 , closeCount)
            if closeCount < openCount:
                backtrack(curr_str + ")" , openCount , closeCount + 1)
        backtrack("" , 0 , 0)
        return result