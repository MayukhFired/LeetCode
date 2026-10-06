class Solution:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        def backtrack(start: int , target: int , path: list[int]):
            if len(path) == k:
                if target == 0:
                    result.append(list(path))
                return

            if target < 0:
                return
            
            for i in range(start , 10):
                path.append(i)
                backtrack(i + 1 , target - i , path)
                path.pop()
        result = []
        backtrack(1 , n , [])
        return result