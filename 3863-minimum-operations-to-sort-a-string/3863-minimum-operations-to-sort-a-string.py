class Solution:
    def minOperations(self, s: str) -> int:
        mx = max(s)
        mn = min(s)
        if all(a <= b for a , b in zip(s , s[1:])):
            return 0
        if len(s) == 2:
            return -1
        if s[0] == mn or s[len(s) - 1] == mx:
            return 1
        for i in range(1 , len(s) -1):
            if s[i] == mx or s[i] == mn:
                return 2
        return 3
        