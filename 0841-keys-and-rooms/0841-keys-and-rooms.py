class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = set()
        stack = [0]
        while stack:
            curr_room = stack.pop()
            if curr_room not in visited:
                visited.add(curr_room)
                for key in rooms[curr_room]:
                    stack.append(key)
        return len(visited) == len(rooms)