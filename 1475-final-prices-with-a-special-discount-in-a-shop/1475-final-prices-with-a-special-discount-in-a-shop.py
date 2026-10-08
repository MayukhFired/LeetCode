class Solution:
    def finalPrices(self, prices: list[int]) -> list[int]:
        res = []
        idx = 0
        for i in range(len(prices)):
            newPrice = prices[i]
            for j in range(i + 1 , len(prices)):
                if prices[j] <= prices[i]:
                    newPrice -= prices[j]
                    break
            res.append(newPrice)
        return res