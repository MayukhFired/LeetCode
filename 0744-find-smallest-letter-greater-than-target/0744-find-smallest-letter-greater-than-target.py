class Solution:
    def nextGreatestLetter(self, letters: list[str], target: str) -> str:
        for i in range(len(letters)):
            if letters[i] > target:
                return letters[i]
        return letters[0]