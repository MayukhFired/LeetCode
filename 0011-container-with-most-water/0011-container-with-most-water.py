class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        ans = 0
        while left < right:
            curr_width = right - left
            curr_height = min(height[left] , height[right])
            temp = curr_width * curr_height

            if temp > ans:
                ans = temp

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return ans