class Solution:
    def maxProduct(self, n: int) -> int:
        maxx = 0
        second = 0
        while n != 0:
            temp = n % 10
            if maxx <= temp:
                second = maxx
                maxx = temp
            elif second < temp:
                second = temp
            n = n // 10
        return maxx*second