class SegmentTreeNode:
    def __init__(self , k : int):
        self.prod = 1
        self.remain = [0] * k

class SegmentTree:
    def __init__(self , nums : list[int] , k : int):
        self.n = len(nums)
        self.k = k
        self.tree = [SegmentTreeNode(k) for _ in range(4 * self.n)]
        self.build(nums , 0 , 0 , self.n - 1)
    def merge(self , left: SegmentTreeNode , right: SegmentTreeNode) -> SegmentTreeNode:
        res = SegmentTreeNode(self.k)
        res.prod = (left.prod * right.prod) % self.k

        for i in range(self.k):
            res.remain[i] = left.remain[i]
        for i in range(self.k):
            if right.remain[i] > 0:
                target_mod = (left.prod * i) % self.k
                res.remain[target_mod] += right.remain[i]
        return res
    def build(self , nums: list[int] , curr: int , left: int , right: int):
        if left == right:
            val = nums[left] % self.k
            self.tree[curr].remain[val] = 1
            self.tree[curr].prod = val
            return
        mid = (left + right) // 2
        self.build(nums , 2 * curr + 1 , left , mid)
        self.build(nums , 2 * curr + 2 , mid + 1 , right)
        self.tree[curr] = self.merge(self.tree[2 * curr + 1] , self.tree[2 * curr + 2])
    def update(self , curr: int , low: int , high: int , idx: int , val: int):
        if low == high:
            val %= self.k
            self.tree[curr].remain = [0] * self.k
            self.tree[curr].remain[val] = 1
            self.tree[curr].prod = val
            return
        mid = (low + high) // 2
        if idx <= mid:
            self.update(2 * curr + 1 , low , mid , idx , val)
        else:
            self.update(2 * curr + 2 , mid + 1 , high , idx , val)
        self.tree[curr] = self.merge(self.tree[2 * curr + 1] , self.tree[2 * curr + 2])
    def query(self , curr: int , low: int , high: int , ql: int , qr: int) -> SegmentTreeNode:
        if ql <= low and high <= qr:
            return self.tree[curr]
        mid = (low + high) // 2
        if qr <= mid:
            return self.query(2 * curr + 1 , low , mid , ql , qr)
        if ql > mid:
            return self.query(2 * curr + 2 , mid + 1 , high , ql , qr)
        left_res = self.query(2 * curr + 1 , low , mid , ql , mid)
        right_res = self.query(2 * curr + 2 , mid + 1 , high , mid + 1 , qr)
        return self.merge(left_res , right_res)

class Solution:
    def resultArray(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:
        n = len(nums)
        st = SegmentTree(nums , k)
        ans = []

        for idx , val , start , x in queries:
            st.update(0 , 0 , n - 1 , idx , val)
            if start >= n:
                ans.append(0)
            else:
                res_node = st.query(0 , 0 , n - 1 , start , n - 1)
                ans.append(res_node.remain[x])
        return ans