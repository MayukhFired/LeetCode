class Solution:
    def compress(self, chars: List[str]) -> int:
        write = 0
        i = 0
        n = len(chars)
        while i < n:
            count = 0
            curr_char = chars[i]
            while i < n and curr_char == chars[i]:
                count += 1
                i += 1
            chars[write] = curr_char
            write += 1
            if count > 1:
                for digits in str(count):
                    chars[write] = digits
                    write += 1
        return write