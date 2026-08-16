# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: ListNode) -> int:
        slow = head
        fast = head
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
        prev = None
        curr = slow
        while curr != None:
            new_node = curr.next
            curr.next = prev
            prev = curr
            curr = new_node
        second_half = prev
        first_half = head
        max_sub = 0
        while second_half != None:
            current_sum = first_half.val + second_half.val
            max_sub = max(max_sub , current_sum)
            first_half = first_half.next
            second_half = second_half.next
        return max_sub