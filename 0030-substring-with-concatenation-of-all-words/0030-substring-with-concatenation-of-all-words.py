class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []

        n = len(s)
        word_count = len(words)
        word_len = len(words[0])
        total_len = word_count * word_len

        if n < total_len:
            return []

        word_map = Counter(words)
        ans = []

        for i in range(word_len):
            left = i
            count = 0
            seen = defaultdict(int)

            for right in range(i , n - word_len + 1 , word_len):
                curr_word = s[right : right + word_len]

                if curr_word in word_map:
                    seen[curr_word] += 1
                    count += 1
                    while seen[curr_word] > word_map[curr_word]:
                        left_word = s[left : left + word_len]
                        seen[left_word] -= 1
                        count -= 1
                        left += word_len
                    if count == word_count:
                        ans.append(left)
                        left_word = s[left : left + word_len]
                        seen[left_word] -= 1
                        count -= 1
                        left += word_len
                else:
                    seen.clear()
                    count = 0
                    left = right + word_len
        
        return ans