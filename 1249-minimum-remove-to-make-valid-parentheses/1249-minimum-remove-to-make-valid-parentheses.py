class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        idx = set()

        for i , char in enumerate(s):
            if char == '(':
                stack.append(i)
            elif char == ')':
                if stack:
                    stack.pop()
                else:
                    idx.add(i)
        idx.update(stack)
        res = [char for i  , char in enumerate(s) if i not in idx]
        return "".join(res)