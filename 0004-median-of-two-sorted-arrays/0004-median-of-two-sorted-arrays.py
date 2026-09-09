class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i = 0 
        j = 0
        N = len(nums1) + len(nums2)
        r = []

        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                r.append(nums1[i])
                i += 1
            else:
                r.append(nums2[j])
                j += 1
        while i < len(nums1):
            r.append(nums1[i])
            i += 1
        while j < len(nums2):
            r.append(nums2[j])
            j += 1
        if N % 2 != 0:
            median = r[N // 2]
        else:
            median = (r[(N - 1) // 2] + r[N // 2]) / 2.0
        return median
