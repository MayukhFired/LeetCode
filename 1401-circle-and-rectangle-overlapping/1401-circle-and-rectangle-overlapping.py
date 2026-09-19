class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        def distance(ux: int , uy: int , vx: int , vy: int):
            return (ux - vx)**2 + (uy - vy)**2
        if x1 <= xCenter and xCenter <= x2 and y1 <= yCenter and yCenter <= y2:
            return True
        if x1 <= xCenter and xCenter <= x2 and y1 <= yCenter and yCenter <= y2 + radius:
            return True
        if x1 <= xCenter and xCenter <= x2 and y1 - radius <= yCenter and yCenter <= y1:
            return True
        if x1 <= xCenter and xCenter <= x2 + radius and y1 <= yCenter and yCenter <= y2:
            return True
        if x1 - radius <= xCenter and xCenter <= x1 and y1 <= yCenter and yCenter <= y2:
            return True
        if distance(xCenter , yCenter , x1 , y1) <= radius * radius:
            return True
        if distance(xCenter , yCenter , x2 , y2) <= radius * radius:
            return True
        if distance(xCenter , yCenter , x1 , y2) <= radius * radius:
            return True
        if distance(xCenter , yCenter , x2 , y1) <= radius * radius:
            return True
        return False
        