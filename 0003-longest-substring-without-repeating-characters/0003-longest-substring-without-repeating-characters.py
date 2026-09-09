class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen = {}
        max_len = 0
        left = 0

        for right , curr_char in enumerate(s):
            if curr_char in last_seen and last_seen[curr_char] >= left:
                left = last_seen[curr_char] + 1
            last_seen[curr_char] = right
            max_len = max(max_len , right - left + 1)
        return max_len