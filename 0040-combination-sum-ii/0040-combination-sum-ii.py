class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        res = []
        tempList = []
        candidates.sort()

        def backtrack(total_left: int , index: int):
            if total_left < 0:
                return
            if total_left == 0:
                res.append(tempList[:])
                return

            for i in range(index , len(candidates)):
                if total_left < candidates[i]:
                    break
                
                if i > index and candidates[i] == candidates[i - 1]:
                    continue

                tempList.append(candidates[i])
                backtrack(total_left - candidates[i] , i + 1)
                tempList.pop()
        backtrack(target , 0)
        return res