class Solution:
    def nextGreatestLetter(self, letters: list[str], target: str) -> str:
        # for i in range(len(letters)):
        #     if letters[i] > target:
        #         return letters[i]
        # return letters[0]

        left = 0
        right = len(letters) - 1
        ans = letters[0]

        while left <= right:
            mid = (left + right) // 2
            if letters[mid] > target:
                ans = letters[mid]
                right = mid - 1
            else:
                left = mid + 1
        return ans