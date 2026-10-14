class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9 * num:
            return ""
    # 1---------------------------------------------1
        # ans = []
        # for _ in range(num):
        #     digit = min(9 , sum)
        #     ans.append(str(digit))
        #     sum -= digit
        # return "".join(ans) if sum == 0 else ""
    # 1---------------------------------------------1

        q , r = divmod(sum , 9)
        ans = "9" * q
        if r > 0:
            ans += str(r)
        ans += "0" * (num - len(ans))
        return ans