class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        w1 = len(word1)
        w2 = len(word2)
        result = []
        i = 0
        j = 0

        while i < w1 or j < w2:
            if i < w1:
                result.append(word1[i])
                i += 1

            if j < w2:
                result.append(word2[j])
                j += 1
        return "".join(result)