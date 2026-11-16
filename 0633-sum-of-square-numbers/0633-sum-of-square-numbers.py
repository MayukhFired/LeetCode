class Solution:
    def judgeSquareSum(self, c: int) -> bool:
    # 1-----------------------------------------------------------------1
        # def binary_search(s , e , n):
        #     if s > e:
        #         return False
        #     mid = (s + e) // 2
        #     if mid * mid == n:
        #         return True
        #     elif mid * mid > n:
        #         return binary_search(s , mid - 1 , n)
        #     else:
        #         return binary_search(mid + 1 , e , n)
        
        # for a in range(int(c**0.5) + 1):
        #     b = c - a * a
        #     if binary_search(0 , b , b):
        #         return True
        # return False
    # 1---------------------------------------------------------------1
        
        a = 0
        b = int(sqrt(c))
        while a <= b:
            if (a * a) + (b * b) == c:
                return True
            elif (a * a) + (b * b) > c:
                b -= 1
            else:
                a += 1
        return False