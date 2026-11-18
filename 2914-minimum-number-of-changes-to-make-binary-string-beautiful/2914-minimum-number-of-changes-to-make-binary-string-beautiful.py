class Solution:
    def minChanges(self, s: str) -> int:
    # 1--------------------------------------------------1
        # curr_char = s[0]
        # count = 0
        # min_change = 0

        # for ch in s:
        #     if ch == curr_char:
        #         count += 1
        #         continue

        #     if count % 2 == 0:
        #         count = 1
        #     else:
        #         count = 0
        #         min_change += 1
        #     curr_char = ch
        # return min_change
    # 1-----------------------------------------------------1
        min_change = 0
        for i in range(0 , len(s) , 2):
            if s[i] != s[i + 1]:
                min_change += 1
        return min_change