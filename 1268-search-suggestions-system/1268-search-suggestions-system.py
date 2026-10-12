class Solution:
    def suggestedProducts(self, products: list[str], searchWord: str) -> list[list[str]]:
        products.sort()
        res = []
        curr = ""
        start_idx = 0

        for c in searchWord:
            curr += c
            idx = bisect.bisect_left(products , curr , lo=start_idx)
            suggested = []
            for i in range(3):
                if idx + i < len(products):
                    word = products[idx + i]
                    if word.startswith(curr):
                        suggested.append(word)
                    else:
                        break
                else:
                    break
            res.append(suggested)
            start_idx = idx
        return res