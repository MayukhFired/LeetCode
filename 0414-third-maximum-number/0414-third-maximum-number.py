class Solution:
    def thirdMax(self, nums: list[int]) -> int:
        # unique_nums = sorted(list(set(nums)))
        # return unique_nums[-3] if len(unique_nums) >= 3 else unique_nums[-1]

        firstMax = (False , float('-inf'))
        secondMax = (False , float('-inf'))
        thirdMax = (False , float('-inf'))

        for num in nums:
            if (firstMax[0] and firstMax[1] == num) or (secondMax[0] and secondMax[1] == num) or(thirdMax[0] and thirdMax[1] == num):
                continue
            if num > firstMax[1] or not firstMax[0]:
                thirdMax = secondMax
                secondMax = firstMax
                firstMax = (True , num)
            elif num > secondMax[1] or not secondMax[0]:
                thirdMax = secondMax
                secondMax = (True , num)
            elif num > thirdMax[1] or not thirdMax[0]:
                thirdMax = (True , num)
        return thirdMax[1] if thirdMax[0] else firstMax[1]