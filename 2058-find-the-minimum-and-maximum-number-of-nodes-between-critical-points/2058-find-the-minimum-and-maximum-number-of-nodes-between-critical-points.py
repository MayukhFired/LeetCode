# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        result = [-1 , -1]
        min_distance = float("inf")
        previous_node = head
        current_node = head.next
        current_index = 1
        pCIndex = 0
        fCIndex = 0

        while current_node.next is not None:
            if(current_node.val < previous_node.val and current_node.val < current_node.next.val) or (current_node.val > previous_node.val and current_node.val > current_node.next.val):
                if pCIndex == 0:
                    pCIndex = current_index
                    fCIndex = current_index
                else:
                    min_distance = min(min_distance , current_index - pCIndex)
                    pCIndex = current_index

            current_index += 1
            previous_node = current_node
            current_node = current_node.next
        if min_distance != float("inf"):
            max_distance = pCIndex - fCIndex
            result = [min_distance , max_distance]
        return result