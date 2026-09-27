class Solution:
    def reverseParentheses(self, s: str) -> str:
        idx = deque()
        res = []

        for curr_char in s:
            if curr_char == '(':
                idx.append(len(res))
            elif curr_char == ')':
                start = idx.pop()
                res[start:] = res[start:][::-1]
            else:
                res.append(curr_char)
        return "".join(res)