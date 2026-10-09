class Solution:
    def minInsertions(self, s: str) -> int:
        insertions = 0
        left = 0
        i = 0
        n = len(s)

        while i < n:
            if s[i] == '(':
                left += 1
                i += 1
            else:
                if i + 1 < n and s[i + 1] == ')':
                    i += 2
                else:
                    insertions += 1
                    i += 1

                if left > 0:
                    left -= 1
                else:
                    insertions += 1
        return insertions + (left * 2)