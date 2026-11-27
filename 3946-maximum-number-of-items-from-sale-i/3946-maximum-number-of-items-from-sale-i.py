class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        f = [0] * (budget + 1)
        mn = min(price for _ , price in items)
        for factor , price in items:
            count = sum(1 for other_factor , _ in items if other_factor % factor == 0)
            for j in range(budget , price -1 , -1):
                if f[j - price] + count > f[j]:
                    f[j] = f[j - price] + count
        
        return max(f[j] + (budget - j) // mn for j in range(budget + 1))