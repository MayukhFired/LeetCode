class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        vis = [False] * 1000
        result = []

        for i in range(len(digits)):
            if digits[i] == 0:
                continue
            for j in range(len(digits)):
                for k in range(len(digits)):
                    if i == j or j == k or k == i:
                        continue
                    if digits[k] % 2 != 0:
                        continue
                    x = digits[i] * 100 + digits[j] * 10 + digits[k]
                    if not vis[x]:
                        vis[x] = True
                        result.append(x)
        return sorted(result)