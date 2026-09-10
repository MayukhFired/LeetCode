class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        result = [0] * (len(temperatures))
        stack = [0] * (len(temperatures))

        top = -1
        for i in range(len(temperatures)):
            while top >= 0 and temperatures[i] > temperatures[stack[top]]:
                result[stack[top]] = i - stack[top]
                top -= 1
            top += 1
            stack[top] = i
        return result