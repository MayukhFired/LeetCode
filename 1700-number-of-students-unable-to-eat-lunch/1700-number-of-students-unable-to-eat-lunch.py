class Solution:
    def countStudents(self, students: list[int], sandwiches: list[int]) -> int:
        counts = [students.count(0) , students.count(1)]
        for s in sandwiches:
            if counts[s] == 0:
                break
            counts[s] -= 1
        return sum(counts)