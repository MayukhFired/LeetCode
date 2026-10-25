# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode | None, k: int) -> ListNode | None:
        if not head:
            return None
        tail = head

        for _ in range(k):
            if not tail:
                return head
            tail = tail.next

        def reverse(curr , end):
            prev = None

            while curr != end:
                next = curr.next
                curr.next = prev
                prev = curr
                curr = next
            return prev
        
        newHead = reverse(head , tail)
        head.next = self.reverseKGroup(tail , k)
        return newHead