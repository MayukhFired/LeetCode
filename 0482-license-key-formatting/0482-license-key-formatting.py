class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        clean_str = s.replace("-" , "").upper()
        result = []

        for i in range(len(clean_str) , 0 , -k):
            start_idx = max(0 , i - k)
            result.append(clean_str[start_idx:i])
        return "-".join(reversed(result))