class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        res = []
        def backtrack(start: int , current_path: List[int] , current_sum: int):
            if current_sum == target:
                res.append(list(current_path))
                return
            if current_sum > target or start >= len(candidates):
                return

            current_path.append(candidates[start])
            backtrack(start , current_path , current_sum + candidates[start])
            current_path.pop()
            backtrack(start + 1, current_path , current_sum)
        backtrack(0 , [] , 0)
        return res