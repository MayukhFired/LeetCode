class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a' , 'e' , 'i' , 'o' , 'u'}
        curr_vowels = 0
        for i in range(k):
            if s[i] in vowels:
                curr_vowels += 1
        max_vowels = curr_vowels
        if max_vowels == k:
            return k
        for j in range(k , len(s)):
            if s[j] in vowels:
                curr_vowels += 1
            if s[j - k] in vowels:
                curr_vowels -= 1
            if curr_vowels > max_vowels:
                max_vowels = curr_vowels
            if max_vowels == k:
                return k
        return max_vowels