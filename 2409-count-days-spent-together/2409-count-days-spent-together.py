class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        DaysofMonths = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        prefix_sum = [0]
        for date in DaysofMonths:
            prefix_sum.append(prefix_sum[-1] + date)
        
        def calculate(day: str , prefix_sum: List[int]) -> int:
            month = int(day[:2])
            date = int(day[3:])
            return prefix_sum[month - 1] + date

        AliceArriveDay = calculate(arriveAlice , prefix_sum)
        AliceLeaveDay = calculate(leaveAlice , prefix_sum)
        BobArriveDay = calculate(arriveBob , prefix_sum)
        BobLeaveDay = calculate(leaveBob , prefix_sum)

        return max(0 , min(AliceLeaveDay , BobLeaveDay) - max(AliceArriveDay , BobArriveDay) + 1)