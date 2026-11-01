class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        IndexS = [0] * 200
        IndexT = [0] * 200

        if len(s) != len(t):
            return False

        for i in range(len(s)):
            if IndexS[ord(s[i])] != IndexT[ord(t[i])]:
                return False
            IndexS[ord(s[i])] = i + 1
            IndexT[ord(t[i])] = i + 1
        return True