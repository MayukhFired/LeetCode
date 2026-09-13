class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        list1 = [(r , c) for r in range(len(img1)) for c in range(len(img1)) if img1[r][c] == 1]
        list2 = [(r , c) for r in range(len(img1)) for c in range(len(img1)) if img2[r][c] == 1]

        vectors = []
        for r1 , c1 in list1:
            for r2 , c2 in list2:
                vectors.append((r2 - r1 , c2 - c1))
        if not vectors:
            return 0
        vector_counts = Counter(vectors)
        return max(vector_counts.values())