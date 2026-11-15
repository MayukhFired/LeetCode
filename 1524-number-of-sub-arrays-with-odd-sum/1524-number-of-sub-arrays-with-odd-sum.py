class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
    # 1--------------------------------------------------------1
        # MOD = 10**9 + 7
        # prefixSum = 0
        # evenCount = 1
        # oddCount = 0
        # count = 0

        # for num in arr:
        #     prefixSum += num
        #     if prefixSum % 2 == 0:
        #         count += oddCount
        #         evenCount += 1
        #     else:
        #         count += evenCount
        #         oddCount += 1

        #     count = count % MOD

        # return count
    # 1-----------------------------------------------------------------1
        MOD = 10**9 + 7
        oddCount = 0
        prefixSum = 0

        for num in arr:
            prefixSum += num
            oddCount += prefixSum % 2

        oddCount += (len(arr) - oddCount) * oddCount
        return oddCount % MOD