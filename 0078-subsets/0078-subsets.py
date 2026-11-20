class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        output = [[]]

        for num in nums:
            subsets = []
            for curr in output:
                temp = curr.copy()
                temp.append(num)
                subsets.append(temp)
            for curr in subsets:
                output.append(curr)
        
        return output