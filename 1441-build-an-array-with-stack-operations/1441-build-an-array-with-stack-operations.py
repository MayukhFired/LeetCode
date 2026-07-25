class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        result = []
        s = 1
        t = 0
        while t < len(target) and s <= n:
            if target[t] == s:
                result.append("Push")
                t += 1
            else:
                result.append("Push")
                result.append("Pop")
            s += 1

        return result
        