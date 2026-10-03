class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        # min_heap = nums[:k]
        # heapq.heapify(min_heap)

        # for num in nums[k:]:
        #     if num > min_heap[0]:
        #         heapq.heappushpop(min_heap , num)
        # return min_heap[0]

        pivot = random.choice(nums)

        left = [x for x in nums if x > pivot]
        mid = [x for x in nums if x == pivot]
        right = [x for x in nums if x < pivot]

        L , M = len(left) , len(mid)

        if k <= L:
            return self.findKthLargest(left , k)
        elif k <= L + M:
            return pivot
        else:
            return self.findKthLargest(right , k - L - M)