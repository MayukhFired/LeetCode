# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode | None, x: int) -> ListNode | None:
        lessHead = ListNode(0)
        greatHead = ListNode(0)

        lessTail = lessHead
        greatTail = greatHead

        curr = head

        while curr:
            if curr.val < x:
                lessTail.next = curr
                lessTail = lessTail.next
            else:
                greatTail.next = curr
                greatTail = greatTail.next
            curr = curr.next
        greatTail.next = None
        lessTail.next = greatHead.next
        return lessHead.next