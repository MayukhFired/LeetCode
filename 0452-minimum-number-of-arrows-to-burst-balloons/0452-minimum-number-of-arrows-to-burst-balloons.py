class Solution:
    def findMinArrowShots(self, points: list[list[int]]) -> int:
        points.sort(key = lambda x : x[0])
        arrows = 1
        end = points[0][1]

        for ballon in points[1:]:
            if ballon[0] > end:
                arrows += 1
                end = ballon[1]
            else:
                end = min(end , ballon[1])
        return arrows