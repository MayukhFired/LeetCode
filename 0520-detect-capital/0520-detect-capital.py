class Solution:
    def detectCapitalUse(self, word: str) -> bool:
    # 1--------------------------------------------------------------------------------1
        # if len(word) == 1:
        #     return True
        # count = 0
        # for i in range(len(word)):
        #     if word[i].isupper():
        #         count += 1
        # if count == 0 or count == len(word) or (count == 1 and word[0].isupper()):
        #     return True
        # return False
    # 1--------------------------------------------------------------------------------1

        return word.isupper() or word.islower() or word.istitle()