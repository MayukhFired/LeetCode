class Solution:
    def subsets(self, nums):
    # 1-----------------------------------------1
        # output = [[]]

        # for num in nums:
        #     subsets = []
        #     for curr in output:
        #         temp = curr.copy()
        #         temp.append(num)
        #         subsets.append(temp)
        #     for curr in subsets:
        #         output.append(curr)
        
        # return output
    # 1-----------------------------------------1
        self.output = []
        self.n = len(nums)
        self.backtrack(0 , [] , nums)
        return self.output

    def backtrack(self , first , curr , nums):
        self.output.append(curr[:])
        for i in range(first , self.n):
            curr.append(nums[i])
            self.backtrack(i + 1 , curr , nums)
            curr.pop()