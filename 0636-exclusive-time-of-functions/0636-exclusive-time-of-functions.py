class Solution:
    def exclusiveTime(self, n: int, logs: list[str]) -> list[int]:
        result = [0] * n
        stack = []
        prev_time = 0

        for log in logs:
            find_id_str , status , timestamp_str = log.split(':')
            find_id = int(find_id_str)
            timestamp = int(timestamp_str)

            if status == 'start':
                if stack:
                    result[stack[-1]] += timestamp - prev_time
                stack.append(find_id)
                prev_time = timestamp
            else:
                popped_id = stack.pop()
                result[popped_id] += timestamp - prev_time + 1
                prev_time = timestamp + 1
        return result