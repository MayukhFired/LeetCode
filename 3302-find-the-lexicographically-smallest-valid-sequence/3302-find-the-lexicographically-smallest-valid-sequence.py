class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        n = len(word1)
        m = len(word2)
        suffix_match = [-1] * (m + 1)
        suffix_match[m] = n
        i = n - 1
        for j in range(m - 1 , -1 , -1):
            while i >= 0 and word1[i] != word2[j]:
                i -= 1
            if i >= 0:
                suffix_match[j] = i
                i -= 1
            else:
                break
        result = []
        i = 0
        changed = False
        for j in range(m):
            if i < n and word1[i] == word2[j]:
                result.append(i)
                i += 1
            else:
                if not changed and i < n and suffix_match[j + 1] > i:
                    result.append(i)
                    i += 1
                    changed = True
                else:
                    while i < n and word1[i] != word2[j]:
                        i += 1
                    if i < n:
                        result.append(i)
                        i += 1
                    else:
                        return []
        return result if len(result) == m else []