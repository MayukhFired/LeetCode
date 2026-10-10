class Solution:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort(key = lambda x : x[1])
    # 1----------------------------------------------1
        # res = 0
        # prev = intervals[0][1]

        # for i in range(1 , len(intervals)):
        #     if prev > intervals[i][0]:
        #         res += 1
        #     else:
        #         prev = intervals[i][1]
        # return res
    # 1------------------------------------------------1

        count = 0
        end = -10**9
        for s , e in intervals:
            if s >= end:
                count += 1
                end = e
        return len(intervals) - count