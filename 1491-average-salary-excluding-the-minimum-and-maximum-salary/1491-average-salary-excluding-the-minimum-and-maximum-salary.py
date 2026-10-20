class Solution:
    def average(self, salary: list[int]) -> float:
        minimum = min(salary)
        maximum = max(salary)
        salary_sum = sum(salary)
        return (salary_sum - minimum - maximum) / (len(salary) - 2)