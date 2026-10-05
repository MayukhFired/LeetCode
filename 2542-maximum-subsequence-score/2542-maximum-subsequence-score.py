class Solution:
    def maxScore(self, nums1: list[int], nums2: list[int], k: int) -> int:
        pairs = []

        for i in range(len(nums1)):
            pairs.append((nums2[i] , nums1[i]))

        pairs.sort(reverse = True)

        minHeap = []
        curr_sum = 0
        max_score = 0

        for n2 , n1 in pairs:
            heapq.heappush(minHeap , n1)
            curr_sum += n1

            if len(minHeap) > k:
                removed = heapq.heappop(minHeap)
                curr_sum -= removed

            if len(minHeap) == k:
                max_score = max(max_score , curr_sum * n2)
        return max_score