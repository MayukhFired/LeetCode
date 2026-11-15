class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        MOD = 10**9 + 7
        prefixSum = 0
        evenCount = 1
        oddCount = 0
        count = 0

        for num in arr:
            prefixSum += num
            if prefixSum % 2 == 0:
                count += oddCount
                evenCount += 1
            else:
                count += evenCount
                oddCount += 1

            count = count % MOD

        return count