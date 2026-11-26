class Solution:
    def canAliceWin(self, n: int) -> bool:
    # 1--------------------------------------------1
        # k = (21 - sqrt(441 - 8 * n)) // 2
        # return k % 2 == 1
    # 1--------------------------------------------1
        take , k = 10 , 0
        while n >= take:
            n -= take
            take -= 1
            k += 1
        return k % 2 == 1