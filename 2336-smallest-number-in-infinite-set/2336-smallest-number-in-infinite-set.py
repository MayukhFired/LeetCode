class SmallestInfiniteSet:

    def __init__(self):
        self.curr_smallest = 1
        self.added_back_heap = []
        self.added_back_set = set()

    def popSmallest(self) -> int:
        if self.added_back_heap:
            smallest = heapq.heappop(self.added_back_heap)
            self.added_back_set.remove(smallest)
            return smallest
        
        smallest = self.curr_smallest
        self.curr_smallest += 1
        return smallest

    def addBack(self, num: int) -> None:
        if num < self.curr_smallest and num not in self.added_back_set:
            heapq.heappush(self.added_back_heap , num)
            self.added_back_set.add(num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)