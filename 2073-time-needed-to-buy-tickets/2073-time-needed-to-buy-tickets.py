class Solution:
    def timeRequiredToBuy(self, tickets: list[int], k: int) -> int:
        ans = 0
        for i in range(len(tickets)):
            ans += min(tickets[k] - (i > k) , tickets[i])
        return ans