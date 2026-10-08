class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        maxArea = 0
        stack = []

        for i in range(len(heights) + 1):
            curr_height = heights[i] if i < len(heights) else 0
            while stack and heights[stack[-1]] >= curr_height:
                height = heights[stack.pop()]
                width = i if not stack else (i - stack[-1] - 1)
                maxArea = max(maxArea , height * width)
            stack.append(i)
        return maxArea