class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        repeats = math.ceil(len(b) / len(a))

        if b in (a * repeats):
            return repeats
        if b in (a * (repeats + 1)):
            return repeats + 1
        return -1