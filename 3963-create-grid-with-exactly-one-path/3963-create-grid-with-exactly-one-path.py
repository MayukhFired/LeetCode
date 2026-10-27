class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
    # 1--------------------------------------------------------1
        # return ['.' * n] + ['#' * (n - 1) + '.'] * (m - 1)
    # 1--------------------------------------------------------1
        arr = [("." + "#" * (n-1)) for i in range(m-1)]
        arr.append("."* n)

        
        return arr