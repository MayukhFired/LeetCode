# class MinStack(object):

#     def __init__(self):
#         self.stack = []

#     def push(self, value):
#         if not self.stack:
#             self.stack.append((value , value))
#         else:
#             current_min = self.stack[-1][1]
#             new_min = min(value , current_min)
#             self.stack.append((value , new_min)) 
        

#     def pop(self):
#         self.stack.pop()
        

#     def top(self):
#         return self.stack[-1][0]
        

#     def getMin(self):
#         return self.stack[-1][1]
        

class MinStack(object):

    def __init__(self):
        self.min = 2147483650
        self.stack = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        if len(self.stack) == 0:
            self.min = val
            self.stack.append(val)
            return

        if val < self.min:
            self.stack.append(2*val - self.min)
            self.min = val
        else:
            self.stack.append(val)
        

    def pop(self):
        """
        :rtype: None
        """

        if len(self.stack) == 0:
            return None

        if self.stack[-1] < self.min:
            self.min = 2*self.min - self.stack[-1]
            self.stack.pop()
        else:
            self.stack.pop()
    
    def top(self):
        """
        :rtype: int
        """

        if self.stack[-1] < self.min:
            return self.min
        else:
            return self.stack[-1]
        

    def getMin(self):
        """
        :rtype: int
        """

        return self.min