class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        suffix_nums = [0] * (n + 1)
        for i in range(n - 1 , -1 , -1):
            suffix_nums[i] = suffix_nums[i + 1] + piles[i]
        memo = [[-1] * (n + 1) for _ in range(n)]

        def Solve(i: int , m: int) -> int:
            if i + 2 * m >= n:
                return suffix_nums[i]
            if memo[i][m] != -1:
                return memo[i][m]
            max_stone = 0
            for x in range(1 , 2*m + 1):
                opponent_score = Solve(i + x , max(m , x))
                current_score = suffix_nums[i] - opponent_score
                max_stone = max(max_stone , current_score)
            memo[i][m] = max_stone
            return memo[i][m]
        return Solve(0 , 1)