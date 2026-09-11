class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        #Brute Force

        # vis = [False] * 1000
        # result = []

        # for i in range(len(digits)):
        #     if digits[i] == 0:
        #         continue
        #     for j in range(len(digits)):
        #         for k in range(len(digits)):
        #             if i == j or j == k or k == i:
        #                 continue
        #             if digits[k] % 2 != 0:
        #                 continue
        #             x = digits[i] * 100 + digits[j] * 10 + digits[k]
        #             if not vis[x]:
        #                 vis[x] = True
        #                 result.append(x)
        # return sorted(result)

        #Optimal Approach
        result = []
        count = [0] * 10
        for i in range(len(digits)):
            count[digits[i]] += 1
        
        for num in range(100 , 1000 , 2):
            d1 = num // 100
            d2 = (num // 10) % 10
            d3 = num % 10

            count[d1] -= 1
            count[d2] -= 1
            count[d3] -= 1

            if count[d1] >= 0 and count[d2] >= 0 and count[d3] >= 0:
                result.append(num)
            
            count[d1] += 1
            count[d2] += 1
            count[d3] += 1
        return sorted(result)