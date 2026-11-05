class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        count = 0
        for i in range(len(arr1)):
            ok = True
            for j in range(len(arr2)):
                ok = ok and (abs(arr1[i] - arr2[j]) > d)
            count += 1 if ok else 0
        return count