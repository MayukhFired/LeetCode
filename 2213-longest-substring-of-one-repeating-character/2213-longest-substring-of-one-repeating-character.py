class Node:
    def __init__(self, ch=None):
        # Initialize properties for a single character leaf node
        self.max_len = 1
        self.pref_len = 1
        self.suff_len = 1
        self.left_char = ch
        self.right_char = ch

class SegmentTree:
    def __init__(self, s):
        self.n = len(s)
        self.tree = [None] * (4 * self.n)
        self.build(s, 0, 0, self.n - 1)

    def merge(self, left, right, left_size, right_size):
        parent = Node()
        # Inherit boundary characters
        parent.left_char = left.left_char
        parent.right_char = right.right_char
        
        # Base prefix and suffix lengths
        parent.pref_len = left.pref_len
        parent.suff_len = right.suff_len
        
        # Base max length is the best of either side
        parent.max_len = max(left.max_len, right.max_len)
        
        # Check if characters meet at the boundary center
        if left.right_char == right.left_char:
            bridge_len = left.suff_len + right.pref_len
            parent.max_len = max(parent.max_len, bridge_len)
            
            # If the entire left child is one uniform character, the prefix extends deep into the right
            if left.pref_len == left_size:
                parent.pref_len = left_size + right.pref_len
            # If the entire right child is uniform, the suffix extends deep into the left
            if right.suff_len == right_size:
                parent.suff_len = right_size + left.suff_len
                
        return parent

    def build(self, s, node, start, end):
        if start == end:
            self.tree[node] = Node(s[start])
            return
        mid = (start + end) // 2
        self.build(s, 2 * node + 1, start, mid)
        self.build(s, 2 * node + 2, mid + 1, end)
        self.tree[node] = self.merge(self.tree[2 * node + 1], self.tree[2 * node + 2], mid - start + 1, end - mid)

    def update(self, node, start, end, idx, ch):
        if start == end:
            self.tree[node] = Node(ch)
            return
        mid = (start + end) // 2
        if start <= idx <= mid:
            self.update(2 * node + 1, start, mid, idx, ch)
        else:
            self.update(2 * node + 2, mid + 1, end, idx, ch)
        self.tree[node] = self.merge(self.tree[2 * node + 1], self.tree[2 * node + 2], mid - start + 1, end - mid)

class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) ->  List[int]:
        st = SegmentTree(s)
        results = []
    
        for ch, idx in zip(queryCharacters, queryIndices):
            st.update(0, 0, st.n - 1, idx, ch)
            results.append(st.tree[0].max_len)
        
        return results
        