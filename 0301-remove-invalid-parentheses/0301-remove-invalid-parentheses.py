class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        # def isValid(string: str) -> bool:
        #     balance = 0
        #     for char in string:
        #         if char == '(':
        #             balance += 1
        #         elif char == ')':
        #             balance -= 1
        #             if balance < 0:
        #                 return False
        #     return balance == 0
        # if not s:
        #     return [""]
        
        # queue = deque([s])
        # visited = {s}
        # result = []
        # found = False

        # while queue:
        #     level_size = len(queue)
        #     level_solutions = []

        #     for _ in range(level_size):
        #         curr = queue.popleft()

        #         if isValid(curr):
        #             level_solutions.append(curr)
        #             found = True
        #         if found:
        #             continue
                
        #         for i in range(len(curr)):
        #             if curr[i] not in ('(' , ')'):
        #                 continue
        #             next_state = curr[:i] + curr[i + 1:]
        #             if next_state not in visited:
        #                 visited.add(next_state)
        #                 queue.append(next_state)
        #     if found:
        #         return level_solutions
        # return [""]

        rem_left = 0
        rem_right = 0

        for char in s:
            if char == '(':
                rem_left += 1
            elif char == ')':
                if rem_left > 0:
                    rem_left -= 1
                else:
                    rem_right += 1
        result = set()

        def dfs(index , left_to_rem , right_to_rem , balance , current_str):
            if index == len(s):
                if left_to_rem == 0 and right_to_rem == 0 and balance == 0:
                    result.add(current_str)
                return

            if balance < 0:
                return 
            char = s[index]

            if char == '(' and left_to_rem > 0:
                dfs(index + 1 , left_to_rem - 1 , right_to_rem , balance , current_str)
            elif char == ')' and right_to_rem > 0:
                dfs(index + 1 , left_to_rem , right_to_rem - 1 , balance , current_str)

            if char == '(':
                dfs(index + 1 , left_to_rem , right_to_rem , balance + 1 , current_str + char)
            elif char == ')':
                dfs(index + 1 , left_to_rem , right_to_rem , balance - 1 , current_str + char)
            else:
                dfs(index + 1 , left_to_rem , right_to_rem , balance , current_str + char)

        dfs(0 , rem_left , rem_right , 0 , "")
        return (list(result))
