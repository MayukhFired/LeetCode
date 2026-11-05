class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
    # 1-------------------------------------------------------------------------------1
        # count = 0
        # for i in range(len(arr1)):
        #     ok = True
        #     for j in range(len(arr2)):
        #         ok = ok and (abs(arr1[i] - arr2[j]) > d)
        #     count += 1 if ok else 0
        # return count
    # 1-------------------------------------------------------------------------------1
        count = 0
        arr2.sort()
        for i in range(len(arr1)):
            x = arr1[i]
            left = 0
            right = len(arr2)

            while left < right:
                mid = (left + right) // 2
                if arr2[mid] < x:
                    left = mid + 1
                else:
                    right = mid
            p = left
            ok = True
            if p < len(arr2):
                ok = ok and (arr2[p] - x > d)
            if p - 1 >= 0 and p - 1 < len(arr2):
                ok = ok and (x - arr2[p - 1] > d)
            count += 1 if ok else 0
        return count